# sudoku-solver-wasm

A fast Sudoku solver compiled to WebAssembly from C.

The solving logic is written in C using a **backtracking algorithm** and compiled to WASM via [Emscripten](https://emscripten.org/). The JS layer is a thin wrapper that handles input/output conversion — no runtime dependencies.

## Install

```sh
npm install sudoku-solver-wasm
```

## Usage

```js
import { solve } from 'sudoku-solver-wasm';
```

`solve(grid)` accepts either a **2D array** or a **flat 81-character string** and always returns a `number[][]`, or `null` if the puzzle has no solution or the input is invalid (wrong length, invalid characters).

```js
// 2D array input
const solved = solve([
    [0, 1, 0, 0, 0, 0, 0, 6, 9],
    [4, 0, 6, 0, 0, 0, 0, 7, 5],
    [7, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 7, 0, 4, 0, 0],
    [1, 0, 0, 0, 2, 0, 0, 0, 0],
    [3, 0, 0, 5, 0, 1, 9, 0, 0],
    [0, 2, 7, 0, 0, 3, 0, 0, 0],
    [0, 0, 0, 9, 0, 0, 0, 0, 7],
    [0, 0, 9, 0, 0, 0, 8, 0, 0]
]);

// Flat string input
const solved = solve('687004910913000000254700000045090001006105040000000200400560030002473090508921704');
```

Or use `solveFlat()` with the same inputs if you need the result as a flat string instead of a 2D array.

## How it works

The solver is written in C and uses a classic **backtracking algorithm**:

1. Find the first empty cell (`0`)
2. Try each digit `1–9`, checking row, column, and 3×3 box constraints
3. Recurse — if no digit fits, backtrack and try the next one

## Build from source

Requires [emsdk](https://emscripten.org/docs/getting_started/downloads.html) and Node.js 22+.

```sh
npm install
npm run build
```
