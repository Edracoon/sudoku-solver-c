import { solve } from "sudoku-solver-wasm";

// With string input
const easyGrid = '687004910913000000254700000045090001006105040000000200400560030002473090508921704';
const solved = solve(easyGrid);
console.log(solved);

// With 2D array input
const expertGrid = [
    [0, 1, 0, 0, 0, 0, 0, 6, 9],
    [4, 0, 6, 0, 0, 0, 0, 7, 5],
    [7, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 7, 0, 4, 0, 0],
    [1, 0, 0, 0, 2, 0, 0, 0, 0],
    [3, 0, 0, 5, 0, 1, 9, 0, 0],
    [0, 2, 7, 0, 0, 3, 0, 0, 0],
    [0, 0, 0, 9, 0, 0, 0, 0, 7],
    [0, 0, 9, 0, 0, 0, 8, 0, 0]
];
const solvedExpert = solve(expertGrid);
console.log(solvedExpert);