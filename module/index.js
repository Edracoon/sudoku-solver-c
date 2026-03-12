import SudokuModule from './sudoku.js';

const mod = await SudokuModule();
const _solve = mod.cwrap('solve', 'string', ['string']);

export function solve(flat) {
    const result = _solve(flat);
    return result === '' ? null : result;
}
