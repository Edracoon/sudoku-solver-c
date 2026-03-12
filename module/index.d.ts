/** Solves a sudoku puzzle.
 * @param flat 81-char string, row-major, '0' = empty cell, '1'-'9' = given
 * @returns solved 81-char string, or null if invalid/unsolvable
 */
export declare function solveFlat(grid: number[][] | string): string | null;

/** Solves a sudoku puzzle.
 * @param grid 9x9 2D array of numbers, 0 = empty cell, 1-9 = given
 * @returns solved 9x9 2D array of numbers, or null if invalid/unsolvable
 */
export declare function solve(grid: number[][] | string): number[][] | null;
