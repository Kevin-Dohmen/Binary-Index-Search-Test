# Build

## Linux (WSL2 Ubuntu in my case)

### Prepare

```bash
sudo apt install g++
mkdir out
```

### Compile

```bash
g++ main.cpp -o ./out/main -O2 -frename-registers
```
> you could add `-march=native` but it didn't make a difference for me.

### Run

```bash
./out/main
```
