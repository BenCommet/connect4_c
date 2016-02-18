#include "connect4_engine.h"

int check_horizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

	for(int i = 0; i < num_rows; i++){
		int count = 0;
		int player = -1;
		for(int j = 0; j < num_columns; j++){
			if(board[i][j] == -1){
				player = -1;
				count = 0;
			}
			else if(count == 0){
				player = board[i][j];
				count = 1;
			}
			else if(board[i][j] == player){
				count = count + 1;
			}
			else{
				count = 1;
				player = board[i][j];
			}
			if(count == length_to_win){
                return player;
			}
		}
	}
	return -1;
}

int check_vertical(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]){
    for(int i = 0; i < num_columns; ++i){
    	int count = 0;
    	int player = -1;
    	for (int j = 0; j < num_rows; j++){
			if(array[j][i] == -1){
				player = -1;
				count = 0;
			}
			else if(count == 0){
				player = array[j][i];
				count = 1;
			}
			else if(array[j][i] == player){
				count = ++count;
			}
			else{
				count = 1;
				player = array[j][i];
			}
			if(count == length_to_win){
                return player;
			}
		}
    }
    return -1;
}

int check_diagonal_left(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]){
    int maxRows = num_columns + num_rows - 2;
    int count = 0;
    int player = -1;
    for (int current_row = 0; current_row < maxRows; current_row++){
        for(int i = 0; i < num_rows; ++i){
            for(int j = 0; j < num_columns; j++){
                if(i + j - current_row == 0){
                	if(array[i][j] == -1){
                		count = 0;
                		player = -1;
                	}
                	else if(array[i][j] != player){
                		count = 1;
                		player = array[i][j];
                	}
                	else{
                		count += 1;
                	}
                	if(count == length_to_win){
                		return player;
                	}
                }
            }
        }
    }
    return -1;
}

int check_diagonal_right(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]){
    int player = -1;
	for(int i = 0; i < num_rows - (length_to_win - 1); i++){
		for(int j = 0; j < num_columns - (length_to_win - 1); j++){
			if(array[i][j] != -1){
				int temp = array[i][j];
				int flag = 1;
				for(int k = 1; k < length_to_win; k++){
					if(temp != array[i + k][j + k]){
						flag = -1;
					}
            	}
            	if(flag == 1){
            		return temp;
            	}
        	}
		}
	}
	return -1;
	}
    

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]){
	if(column > num_columns){
        return -1;
	}
	if(board[0][column] != -1){
		return -1;
	}
	for(int i = num_rows; i > 0; --i){
		if(board[i][column] == -1){
			board[i][column] = player;
			return 1;
		}
	}
	return -1;
}

int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]){

	if(length_to_win < 1){
		return -1;
	}
	if(num_rows == 0 || num_columns == 0){
		return -1;
	}
	int horizontal = check_horizontal(num_rows, num_columns, length_to_win, array);
	int vertical = check_vertical(num_rows, num_columns, length_to_win, array);
	int diagonal_left = check_diagonal_left(num_rows, num_columns, length_to_win, array);
	int diagonal_right = check_diagonal_right(num_rows, num_columns, length_to_win, array);

	if( horizontal != -1){
		return horizontal;
	}
	if(vertical != -1){
		return vertical;
	}
	if(diagonal_left != -1){
		return diagonal_left;
	}
	if(diagonal_right != -1){
		return diagonal_right;
	}
	return -1;
}
