import { solve } from './module/index.js';

/*
 6 8 7 0 0 4 9 1 0
 9 1 3 0 0 0 0 0 0
 2 5 4 7 0 0 0 0 0
 0 4 5 0 9 0 0 0 1
 0 0 6 1 0 5 0 4 0
 0 0 0 0 0 0 2 0 0
 4 0 0 5 6 0 0 3 0
 0 0 2 4 7 3 0 9 0
 5 0 8 9 2 1 7 0 4
 */
const easyGrid = '687004910913000000254700000045090001006105040000000200400560030002473090508921704';
const solved = solve(easyGrid);
console.log("Solution found:", solved);