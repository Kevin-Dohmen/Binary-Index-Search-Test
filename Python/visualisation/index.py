import matplotlib.pyplot as plt
import random

class index:
    arr: list[int]

    fig, ax = plt.subplots()

    frame_count: int = 0
    save_path: str|None = None

    def __init__(self, arr: list[int], save_path: str|None = None):
        self.arr = arr
        # batching / tracking state
        self.read_indices: set[int] = set()
        self.write_indices: set[int] = set()
        self.op_count = 0
        self.batch_size = 5
        self.save_path = save_path
        self.init_plot()

    def get(self, index: int) -> int:
        self.record_op('read', index)
        return self.arr[index]

    def set(self, index: int, value: int):
        self.arr[index] = value
        self.record_op('write', index)

    def append(self, value: int):
        self.arr.append(value)
        self.record_op('write', len(self.arr) - 1)
    
    def pop(self, index: int) -> int:
        val = self.arr.pop(index)
        # mark as a write at that index and adjust tracked indices
        self.record_op('write', index)
        # remove any tracked indices that are now out-of-range
        self.read_indices = {i for i in self.read_indices if i < len(self.arr)}
        self.write_indices = {i for i in self.write_indices if i < len(self.arr)}
        return val
    
    def __len__(self):
        return len(self.arr)

    def __getitem__(self, index):
        if isinstance(index, slice):
            # handle slice: return list slice and record reads for all indices
            start, stop, step = index.indices(len(self.arr))
            for i in range(start, stop, step or 1):
                self.record_op('read', i)
            return self.arr[index]
        else:
            # handle integer index
            return self.get(index)

    def __setitem__(self, index: int, value: int):
        self.set(index, value)
    
    def init_plot(self):
        self.ax.set_xlim(-1, len(self.arr))
        max_h = max(self.arr) + 1 if self.arr else 1
        self.ax.set_ylim(0, max_h)
        self.bars = self.ax.bar(range(len(self.arr)), self.arr, color='grey')
        plt.ion()
        plt.show()

    def record_op(self, kind: str, index: int | None):
        if index is None:
            return
        if kind == 'read':
            self.read_indices.add(index)
        else:
            self.write_indices.add(index)
        self.op_count += 1
        if self.op_count % self.batch_size == 0:
            self.update()
    
    def setTitle(self, title: str):
        plt.title(title)

    def update(self):
        # if number of bars changed (append/pop), recreate them
        if not hasattr(self, 'bars') or len(self.bars) != len(self.arr):
            self.ax.clear()
            self.bars = self.ax.bar(range(len(self.arr)), self.arr, color='grey')
        else:
            # update heights in place
            for i, h in enumerate(self.arr):
                try:
                    self.bars[i].set_height(h)
                except Exception:
                    pass

        # color bars based on cumulative read/write sets
        for i, bar in enumerate(self.bars):
            if i in self.write_indices:
                bar.set_color('red')
            elif i in self.read_indices:
                bar.set_color('green')
            else:
                bar.set_color('grey')
        
        self.read_indices.clear()
        self.write_indices.clear()

        self.ax.set_xlim(-1, len(self.arr))
        max_h = max(self.arr) + 1 if self.arr else 1
        self.ax.set_ylim(0, max_h)
        self.fig.canvas.draw()
        self.fig.canvas.flush_events()\
        
        # save
        if self.save_path:
            self.fig.savefig(f"{self.save_path}/frame_{self.frame_count:04d}.png")
            self.frame_count += 1


