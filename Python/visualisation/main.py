import matplotlib.pyplot as plt
import random
from index import index

def shuffle(idx: index):
    for i in range(len(idx)):
        randomIdx = random.randint(0, len(idx) - 1)

        tmp = idx[randomIdx]
        idx[randomIdx] = idx[i]
        idx[i] = tmp

def bubble(idx: index):
    for i in range(len(idx), 0, -1):
        for j in range(1, i):
            cur = idx[j]
            prev = idx[j - 1]
            if prev > cur:
                idx[j] = prev
                idx[j - 1] = cur

def merge_merge(idx: index, left: int, mid: int, right: int):
    n1 = mid - left + 1
    n2 = right - mid

    # split
    L = idx[left : mid + 1]
    R = idx[mid + 1 : right + 1]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            idx[k] = L[i]
            i += 1
        else:
            idx[k] = R[j]
            j += 1
        k += 1
    
    while i < n1:
        idx[k] = L[i]
        i += 1
        k += 1
    
    while j < n2:
        idx[k] = R[j]
        j += 1
        k += 1

def merge_split_merge(idx: index, left: int, right: int):
    if left < right:
        mid = (left + right) // 2
        merge_split_merge(idx, left, mid)
        merge_split_merge(idx, mid + 1, right)
        merge_merge(idx, left, mid, right)

def merge(idx: index):
    merge_split_merge(idx, 0, len(idx) - 1)

def main():
    # idx = index([i for i in range (1, 101)], "./frames") # for vid
    idx = index([i for i in range (1, 101)])

    print(len(idx))

    idx.batch_size = 10
    for _ in range(1):
        for i in range(len(idx)):
            tmp = idx[i]

    idx.setTitle("shuffle")

    idx.batch_size = 20
    shuffle(idx)

    idx.setTitle("Bubble Sort")

    idx.batch_size = 50
    bubble(idx)

    idx.setTitle("")

    idx.batch_size = 10
    for _ in range(2):
        for i in range(len(idx)):
            tmp = idx[i]

    idx.setTitle("shuffle")

    idx.batch_size = 20
    shuffle(idx)

    idx.setTitle("Merge Sort")

    idx.batch_size = 10
    merge(idx)

    idx.setTitle("")

    idx.batch_size = 10
    for _ in range(5):
        for i in range(len(idx)):
            tmp = idx[i]

if __name__ == "__main__":
    main()