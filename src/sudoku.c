/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 15:15:56 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static char g_solved_flat[82];

const char *get_solved_flat(void)
{
    return (g_solved_flat);
}

void print_grid(char cpy_grid[9][9])
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < 9)
    {
        while (x < 9)
        {
            if (x > 0)
                write(1, " ", 1);
            write(1, &cpy_grid[y][x], 1);
            x++;
        }
        write(1, "\n", 1);
        x = 0;
        y++;
    }
}

void copy_grid(char grid[9][9], char cpy_grid[9][9])
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < 9)
    {
        while (x < 9)
        {
            cpy_grid[y][x] = grid[y][x];
            x++;
        }
        x = 0;
        y++;
    }
}

int fill_curr_case(int x, int y, char cpy_grid[9][9])
{
    int value;

    value = '1';
    while (value <= '9')
    {
        if (check_line_row(x, y, value, cpy_grid))
        {
            cpy_grid[y][x] = value;
            if (check_3x3(x, y, value, cpy_grid))
                if ((solve_grid(cpy_grid)))
                    return (1);
        }
        value++;
    }
    return (0);
}

int solve_grid(char grid[9][9])
{
    char cpy_grid[9][9];
    int x;
    int y;
    int i;

    copy_grid(grid, cpy_grid);
    x = 0;
    y = 0;
    while (y < 9)
    {
        while (x < 9)
        {
            if (cpy_grid[y][x] == '0')
                return (fill_curr_case(x, y, cpy_grid));
            x++;
        }
        x = 0;
        y++;
    }

    // Grid is solved
    i = 0;
    while (i < 81)
    {
        g_solved_flat[i] = cpy_grid[i / 9][i % 9];
        i++;
    }
    g_solved_flat[81] = '\0';
    return (1);
}

int check_and_solve(char grid[9][9])
{
    if (check_grid(grid) == -1)
    {
        write(STDERR_FILENO, "Error : grid file invalid\n", 28);
        return (0);
    }
    if (!solve_grid(grid))
    {
        write(1, "Error : No Solve\n", 17);
        return (0);
    }
    return (1);
}
