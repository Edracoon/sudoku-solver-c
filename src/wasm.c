#include "sudoku.h"
#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
const char *solve(const char *flat)
{
    char grid[9][9];
    int i;

    if (!flat)
        return ("");
    i = 0;
    while (i < 81 && flat[i])
    {
        if (!(flat[i] >= '0' && flat[i] <= '9'))
            return ("");
        grid[i / 9][i % 9] = flat[i];
        i++;
    }
    if (i != 81)
        return ("");
    if (!solve_grid(grid))
        return ("");
    return (get_solved_flat());
}
