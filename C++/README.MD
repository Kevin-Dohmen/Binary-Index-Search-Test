# Build

## Linux (WSL2 Ubuntu in my case)

### Prepare

```bash
sudo apt install g++ # build-essential
sudo apt install mingw-w64 # optional for cross-compiling but i got INSANE performance with it
mkdir out
```

### Compile

```bash
# G++
g++ main.cpp -o ./out/main -O2 -frename-registers

# mingw-w64 (cross-compile for Windows and Linux)
x86_64-w64-mingw32-g++ main.cpp -o ./out/main.exe -O2 -frename-registers
```

> you could add `-march="native"` but it didn't make a difference for me.

### Run

```bash
./out/main
```
