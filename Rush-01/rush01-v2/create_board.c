/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:46:01 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 01:44:02 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include "check_posb.c"


#include <stdlib.h>
#include "struct.h"
#define	S_SIZE	9

void	initialise_square(char **argv, t_square **board, int row, int col)
{
	int tmp_index;

	if (argv[row + 1][col] == '.')
	{
		board[row][col].posb = (char*)malloc(sizeof(char) * (S_SIZE + 1));
		tmp_index = -1;
		while (++tmp_index < S_SIZE)
			*(board[row][col].posb + tmp_index) = tmp_index + '1';
		*(board[row][col].posb + tmp_index) = '\0';
		board[row][col].length = S_SIZE;
		board[row][col].mode = 1;
	}
	else
	{
		board[row][col].posb = (char*)malloc(sizeof(char) * 2);
		*(board[row][col].posb) = argv[row + 1][col];
		*(board[row][col].posb + 1) = '\0';
		board[row][col].length = 1;
		board[row][col].mode = 0;
	}
}

void	create_board(char **argv, t_square **board)
{
	int			row;
	int			col;

	row = -1;
	col = -1;
	while (++row < S_SIZE)
	{
		board[row] = (t_square*)malloc(sizeof(t_square) * S_SIZE);
		col = -1;
		while (++col < S_SIZE)
		{
			initialise_square(argv, board, row, col);
		}
	}
}

int 	main(int argc, char **argv)
{// the main is just for testing
	int i;
	int j;

	argc = 0;
	i = -1;
	j = -1;
	t_square **board;
	board = (t_square**)malloc(sizeof(t_square*) * S_SIZE);
	create_board(argv, board);
	
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			if (board[i][j].mode != 0)
			{
				check_row(board, i, j);
				check_col(board, i, j);
				check_box(board, i, j);
			}
			if (board[i][j].length == 0)
				printf("ERORR!!!!!!!!!!!!!!!!!"); //THE SUDOKU IS WRONG!!
			printf("%s\t\t", board[i][j].posb);
		}
		printf("\n");
	}
	/*
	i = -1;
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			printf("%s(mod%d, len%d)\t", board[i][j].posb, board[i][j].mode, board[i][j].length);
		}
		printf("\n");
	}*/
}
