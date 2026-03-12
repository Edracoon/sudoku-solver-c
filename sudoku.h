/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epfennig <epfennig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:09:11 by epfennig          #+#    #+#             */
/*   Updated: 2021/09/15 12:10:02 by epfennig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOWERDOKU_H
#define TOWERDOKU_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int			read_file(char *pathname, char grid[9][9]);
int			check_grid(char grid[9][9]);
int			check_and_solve(char grid[9][9]);
int			check_line_row(int x, int y, int value, char cpy_grid[9][9]);
int			check_3x3(int x, int y, int value, char cpy_grid[9][9]);
int			solve_grid(char grid[9][9]);
const char	*get_solved_flat(void);

#endif
