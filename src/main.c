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

int read_file(char *pathname, char grid[9][9])
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

int main(int ac, char **av)
{
    char grid[9][9];

    if (ac != 2)
    {
        write(STDOUT_FILENO, "Error : [./sudoku] [grid]\n", 28);
        return (0);
    }
    if (read_file(av[1], grid) == -1)
    {
        write(STDERR_FILENO, "Error : file invalid\n", 28);
        return (0);
    }
    check_and_solve(grid);
    return (0);
}
