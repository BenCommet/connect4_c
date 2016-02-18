#include "connect4_engine.h"

int check_horizontal(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]){

	for(int i = 0; i < num_rows; i++){
		int count = 0;
		int player = -1;
		for(int j = 0; j < num_columns; j++){
			if(board[i][j] == -1){
                //printf("1");
				player = -1;
				count = 0;
			}
			else if(count == 0){
			   // printf("2");
				player = board[i][j];
				count = 1;
			}
			else if(board[i][j] == player){
			    //printf("3");
				count = count + 1;
			}
			else{
			    //printf("4");
				count = 1;
				player = board[i][j];
			}
			if(count == length_to_win){
               // printf("5");
                return player;
			}
		}
	}
	return -1;
}

int check_vertical(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]){
    for(int i = 0; i < num_columns; i++){
    	int count = 0;
    	int player = -1;
    	for (int j = 0; j < num_rows; j++){
			if(array[i][j] == -1){
				player = -1;
			}
			else if(count == 0){
				player = array[i][j];
				count = 1;
			}
			else if(array[i][j] == player){
				count = ++count;
			}
			else{
				count = 1;
				player = array[i][j];
			}
			if(count == length_to_win){
                return player;
			}
		}
    }
    return -1;
}

int check_diagonal(int num_columns, int num_rows, int length_to_win, int array[num_rows][num_columns]){
    int maxRows = num_columns + num_rows - 2;
    for (int current_row = 0; current_row < maxRows; current_row++){
        for(int i = 0; i < num_rows; ++i){
            int player = -1;
            int count = 0;
            for(int j = 0; j < num_columns; j++){
                if(i + j - current_row == 0){
                    if(array[i][j] == -1){
                        player = -1;
                    }
                    else if(count == 0){
                        player = array[i][j];
                        count = 1;
                    }
                    else if(array[i][j] == player){
                        count = ++count;
                    }
                    else{
                        count = 1;
                        player = array[i][j];
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

	if(num_rows == 0 || num_columns == 0){
		return 2;
	}
	int horizontal = check_horizontal(num_rows, num_columns, length_to_win, array);
	int vertical = check_vertical(num_rows, num_columns, length_to_win, array);
	int diagonal = check_diagonal(num_rows, num_columns, length_to_win, array);

	if( horizontal != -1){
		return horizontal;
	}
	if(vertical != -1){
		return vertical;
	}
	if(diagonal != -1){
		return diagonal;
	}
	return -1;
}
