# Compiling/Running

## Dependencies

- none, just the std libraries

## Prepare

in WSL/Linux:

```bash
sudo apt install g++
sudo apt install mingw-w64
```

## Compile

Compiling is done in WSL/Linux

```bash
make
```

## Cleanup

```bash
make clean
```

## Change compiler

### Compilers

- g++
  - GNU C++ compiler
- x86_64-w64-mingw32-g++
  - MinGW-w64 C++ compiler for 64-bit Windows and Linux
- i686-w64-mingw32-g++
  - MinGW-w64 C++ compiler for 32-bit Windows and Linux
- etc.. (but code now supports these compilers)

### In [Makefile](./Makefile#L15)

```makefile
CXX := [your compiler] # Compiler
```

## Running

```bash
./build/main.exe
```
