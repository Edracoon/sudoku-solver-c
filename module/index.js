import SudokuModule from './sudoku.js';

const mod = await SudokuModule();
const _solve = mod.cwrap('solve', 'string', ['string']);

export function solveFlat(grid) {
    const flat = typeof grid === 'string' ? grid : grid.flat().join('');
    const result = _solve(flat);
    return result === '' ? null : result;
}

export function solve(grid) {
    const flat = typeof grid === 'string' ? grid : grid.flat().join('');
    const solved = _solve(flat);
    if (!solved) return null;
    const solvedGrid = [];
    for (let i = 0; i < 9; i++) {
        solvedGrid.push(solved.slice(i * 9, (i + 1) * 9).split('').map(Number));
    }
    return solvedGrid;
}