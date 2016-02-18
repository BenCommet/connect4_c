#include "connect4_engine.c"
#include <stdio.h>
#include <stdlib.h>
int num_rows;
void ct_initialize(int num_rows, int num_cols, int array[num_rows][num_cols]) {
  int r, c;
  for (r = 0; r < num_rows; r++) {
    for (c = 0; c < num_cols; c++) {
      array[r][c] = -1;
    }
  }
};

void printBoard(int num_rows, int num_columns, int board[num_rows][num_columns]){
      int row, col;

   puts("\n    ****** Connect Four ******\n");
   for(row = 0; row < num_rows; row++){
      for(col = 0; col < num_columns; col++){
      	if(board[row][col] == 0 || board[row][col] == 1) {
      		printf("|  %d ", board[row][col]);
      	}
      	else {
      		printf("| %d ", board[row][col]);
      	}
      }
      puts("|");
   }
}


int game(int num_rows, int num_cols, int length_to_win, int board[num_rows][num_cols]){
	printf("Hello! Welcome to connect4!\n");
	int win = -1;
	while(1){
		int player1_col, player2_col;
		//player 1
		printf("Player 1, select a column:");
		char temp[20];
		scanf("%s", temp);
		player1_col = atoi(temp);
		if (place_token(1, player1_col, num_rows, num_cols, board) == -1){
			printf("That column was full, you lose your turn.\n");
		}
		else{
			printBoard(num_rows, num_cols, board);
		}
		win = winner(num_rows, num_cols, length_to_win, board);
		if(win != -1){
			printf("Congratulations Player %d! You Won!", win);
			break;
		}
		//player 2
		printf("Player 2, select a column:");
		scanf("%s", temp);
		player2_col = atoi(temp);
		if (place_token(2, player2_col, num_rows, num_cols, board) == -1){
			printf("That column was full, you lose your turn.\n");
		}
		else{
			printBoard(num_rows, num_cols, board);
		}
		win = winner(num_rows, num_cols, length_to_win, board);
		if(win != -1){
			printf("Congratulations Player %d! You Won!", win);
			break;
		}
	}

	return -1;
}


int main(int argc, char*argv[]){
	setvbuf(stdout, NULL, _IONBF, 0);
	int num_rows, num_cols, length_to_win;
	if(argc != 4){
		printf("You entered an incorrect number of parameters.\n Please run again with 3 paramaters.\n");
		return 0;
	}

	num_rows = atoi(argv[1]);
	num_cols = atoi(argv[2]);
	length_to_win = atoi(argv[3]);
	int array[num_rows][num_cols];
	ct_initialize(num_rows, num_cols, array);	

	game(num_rows, num_cols, length_to_win, array);

	return 0;

}