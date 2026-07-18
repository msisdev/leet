# leet-cpp

LeetCode C++ solutions workspace.

## Requirements

- CMake >= 3.16
- A C++20 compiler (g++/clang++)

## Build and run

```bash
cmake -S . -B build
cmake --build build
./build/leet_runner 0001
```

## One-command run

```bash
chmod +x scripts/run.sh
./scripts/run.sh 169
```

## Project structure

- `src/main.cpp`: entry point for local demo run
- `problems/`: problem implementations
- `include/problems/`: headers for problem demos
- `scripts/new_problem.sh`: helper script to create new problem files

## Add a new problem

```bash
chmod +x scripts/new_problem.sh
./scripts/new_problem.sh 0121 best-time-to-buy-and-sell-stock
```

Then edit `src/main.cpp` to include and call your new demo function.
