/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:14:25 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 23:07:32 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_H
# define FUNC_H

# define S_SIZE 9

# include <stdlib.h>
# include <unistd.h>

int			ft_sqrt(int i);

int			ft_strlen(char *str);

int			is_numeric_point(char *str);

int			rm_posb(char *posb, int length, char delt);

int			check_col(int **board, int x, int y);

int			check_row(int **board, int x, int y);

int			check_box(int **board, int x, int y);

int			check_all(int **board, int x, int y);

int			check_argv(int argc, char **argv);

void		create_board(char **argv, int **board);

void		display_board(int **board);

int			back_track(int **board, int index, int *nbr_sol, int **board_2);

void		ft_putchar(char c);

void		ft_putstr(char *str);

void		cp_board(int **board, int **board_2);

void		free_memory(int **board);

int			call_cp_board(int **board, int **board_2, int *nbr_sol);

int			check_given_board(int **board);

void		solve(int **board, int **board_2);

#endif
