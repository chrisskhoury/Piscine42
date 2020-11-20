/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:05:01 by celias            #+#    #+#             */
/*   Updated: 2018/07/15 14:04:07 by celias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

int 	main(int argc, char **argv)
{// the main is just for testing
	int i;
	int j;
	int k;
	int back;
	int **board;
	i = -1;
	j = -1;

	if (check_argv(argc, argv))
	{
		board = (int**)malloc(sizeof(int*) * S_SIZE);
		create_board(argv, board);

		while (++i < S_SIZE)
		{
			j = -1;
			while (++j < S_SIZE)
			{
				printf("%d ", board[i][j]);
				if (!check_all(board, i, j))
					printf("ERROR");
			}
			printf("\n");
		}
		printf("START BACK TRACK\n");
		back = back_track(board, 0, 0);
//		if (back == S_SIZE * S_SIZE)
//		{
			i = -1;
			while (++i < S_SIZE)
			{
				j = -1;
				while (++j < S_SIZE)
					printf("%d ", board[i][j]);
				printf("\n");
			}	
//		}
		printf("END OF BACK TRACK");
	}
	else
		printf("ARGUMENT ERROR");


	/*	while (++k < 5){
		i = -1;
		while (++i < 9)
		{
		j = -1;
		while (++j < 9)
		{
		if (board[i][j].mode != 0)
		{
		check_row(board, i, j, 0);
		check_col(board, i, j, 0);
		check_box(board, i, j, 0);
		}
	//printf("%s\t\t", board[i][j].posb);
	}
	printf("\n");
	}

	i = -1;
	while (++i < 9)
	{
	j = -1;
	while (++j < 9)
	{
	if (board[i][j].length == 1)
	{
	if (!(verify_row(board, i ,j)
	&& verify_col(board, i, j)
	&& verify_box(board, i, j)))
	{
	printf("ERROR: TWO CHARACTERS ARE THE SAME");
	return (0);
	}
	else
	board[i][j].mode = 0;
	}
	printf("%s(%d)\t\t", board[i][j].posb, board[i][j].mode);
	if (board[i][j].length == 0)
	printf("ERORR: THE LENGTH IS 0"); //THE SUDOKU IS WRONG!!
	}
	printf("\n");
	}
	}*/
}
