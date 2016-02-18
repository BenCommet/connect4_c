#include <stdio.h>
int check_horizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]);
int check_vertical(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]);
int check_diagonal_left(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]);
int check_diagonal_right(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]);
int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
