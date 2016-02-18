
#include <stdio.h>
#include "connect4_engine.c"

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

   //system("clear");
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

void winner_horizontal() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Horizontal");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[0][1] = 0;
  // array[0][2] = 0;
  // array[0][3] = 0;

  // array[0][3] = 0;
  // array[0][4] = 0;
  // array[0][5] = 0;
  // array[0][6] = 0;

  array[6][3] = 1;
  array[6][4] = 1;
  array[6][5] = 1;
  array[6][6] = 1;

  // array[1][0] = 0;
  // array[1][1] = 0;
  // array[1][2] = 0;
  // array[1][3] = 0;

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_vertical() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Vertical");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[1][0] = 0;
  // array[2][0] = 0;
  // array[3][0] = 0;

  array[3][6] = 1;
  array[4][6] = 1;
  array[5][6] = 1;
  array[6][6] = 1;

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_diagleft() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Left Diag");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[1][0] = 0;
  // array[2][0] = 0;
  // array[3][0] = 0;
  array[0][3] = 1;
  array[1][2] = 1;
  array[2][1] = 1;
  array[3][0] = 1;


  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void winner_diagright() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Right Diag");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[1][0] = 0;
  // array[2][0] = 0;
  // array[3][0] = 0;

  array[0][3] = 0;
  array[1][4] = 0;
  array[2][5] = 0;
  array[3][6] = 0;

  answer = winner(num_rows, num_columns, 4, array);
  printf("%d\n", answer);
  printBoard(num_rows, num_columns, array);
  puts("\n");
}

void testPutToken() {
  puts("\n");
  printf("%s\n", "*********************");
  printf("%s\n", "Testing Insert Token");
  printf("%s\n", "*********************");
  puts("\n");

  int num_rows = 7;
  int num_columns = 7;
  int array[num_rows][num_columns];
  int answer;
  ct_initialize(num_rows, num_columns, array);

  // array[0][0] = 0;
  // array[0][1] = 0;
  // array[0][2] = 0;
  // array[0][3] = 0;

  printBoard(num_rows, num_columns, array);
  answer = place_token(1, 3, num_rows, num_columns, array);
  printf("%d", answer);
  printBoard(num_rows, num_columns, array);
}

int main () {
  testPutToken();
  winner_horizontal();
  winner_vertical();
  winner_diagleft();
  winner_diagright();
}
