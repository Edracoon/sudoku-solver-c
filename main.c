/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 12:36:30 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int read_grid(char *pathname, char grid[9][9])
{
    int fd;
    int r;
    char c;
    int x = 0;
    int y = 0;

    if ((fd = open(pathname, O_DIRECTORY)) > 0)
    {
        close(fd);
        return (-1);
    }
    if ((fd = open(pathname, O_RDONLY)) == -1)
        return (-1);
    while (y < 9 && (r = read(fd, &c, 1)))
    {
        if (c != '\n')
            grid[y][x++] = c;
        else
        {
            x = 0;
            y++;
        }
    }
    close(fd);
    return (0);
}

int check_grid(char grid[9][9])
{
    int x;
    int y = 0;

    while (y < 9)
    {
        x = 0;
        while (x < 9)
        {
            if (!(grid[y][x] >= '0' && grid[y][x] <= '9'))
                return (-1);
            x++;
        }
        y++;
    }
    return (0);
}

int check_and_solve(char grid[9][9])
{
    if (check_grid(grid) == -1)
    {
        write(STDERR_FILENO, "Error : grid file invalid\n", 28);
        return (0);
    }
    if (!solve_grid(grid))
        write(1, "Error : No Solve\n", 17);
    return (1);
}

int main(int ac, char **av)
{
    char grid[9][9];

    if (ac != 2)
    {
        write(STDOUT_FILENO, "Error : [./sudoku] [grid]\n", 28);
        return (0);
    }
    if (read_grid(av[1], grid) == -1)
    {
        write(STDERR_FILENO, "Error : file invalid\n", 28);
        return (0);
    }
    check_and_solve(grid);
    return (0);
}
