#include "connect4_engine.c"
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
   puts("    0   1    2    3    4    5    6\n");
   puts("------------------------------------");
   for(row = num_rows - 1; row >= 0; row--){
      for(col = 0; col < num_columns; col++){
      	if(board[row][col] == 0 || board[row][col] == 1) {
      		printf("|  %d ", board[row][col]);
      	}
      	else {
      		printf("| %d ", board[row][col]);
      	}
      }
      puts("|");
      puts("------------------------------------");
   }
}

int game(int num_rows, int num_cols, int length_to_win, int array[num_rows][num_cols]){
	printf("Hello! Thanks for playing connect 4!\n");
	return -1;
}

int main(int argc, char*argv[]){
	int num_rows, num_cols, length_to_win;
	if(argc != 4){
		printf("You entered an incorrect number of parameters.\n Please run again with 3 paramaters.");
		return 0;
	}

	printf("something");
	num_rows = argv[1];
	num_cols = argv[2];
	length_to_win = argv[3];
	int array[num_rows][num_cols];
	ct_initialize(num_rows, num_cols, array);	
	if(game(num_rows, num_cols, length_to_win, array) == 0){
		printf("Congrats Player 0!\n You Won!\n");
		return 0;
	}
	if(game(num_rows, num_cols, length_to_win, array) == 1){
		printf("Congrats player 1!\n You Won!\n");
		return 0;
	}
	else{
		printf("Congrats Nobody.\n You Both Suck!");
		return 0;
	}
	return 0;

}