import { solve } from '../module/index.js';

const unsolvableGrid = '123456780100000000000000000000000000000000000000000000000000000000000000000000000'
const mediumGrid = '530070000600195000098000060800060003400803001700020006060000280000419005000080079';

let passed = 0;
let failed = 0;

function assert(label, result, expected) {
    const ok = JSON.stringify(result) === JSON.stringify(expected);
    console.log(`${ok ? '✓' : '✗'} ${label}`);
    if (!ok) {
        console.log(`    expected: ${JSON.stringify(expected)}`);
        console.log(`    got:      ${JSON.stringify(result)}`);
    }
    ok ? passed++ : failed++;
}

// 1. Flat string input → 2D array output
const easy = solve(mediumGrid);
assert('flat string input returns number[][]', Array.isArray(easy) && Array.isArray(easy[0]), true);
assert('flat string solved correctly', easy?.[0], [5, 3, 4, 6, 7, 8, 9, 1, 2]);

// 2. 2D array input → 2D array output
const solved = solve([
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9],
]);
assert('2D array input returns number[][]', Array.isArray(solved) && Array.isArray(solved[0]), true);
assert('2D array solved correctly', solved?.[0], [5, 3, 4, 6, 7, 8, 9, 1, 2]);

// 3. Invalid input → null
assert('invalid input returns null', solve('notvalid'), null);
assert('unsolvable puzzle returns null', solve(unsolvableGrid), null);

console.log(`\n${passed} passed, ${failed} failed`);
failed > 0 && process.exit(1);
