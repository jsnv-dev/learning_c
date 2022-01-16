/* Author: Jason Villaluna
 * Written for challenges in course:
 *   https://www.udemy.com/course/c-programming-for-beginners-/
 * Requirements:
 * * write a program that plays tic-tac-toe
 *   * game Is played on a 3x3 grid the game Is played by two players, who take
 *     turns
 * * Create an array to represent the board
 *   * can be of type char and consist of 10 elements (do not use zero)
 *   * each element represents a coordinate on the board that the user can
 *     select
 * * Some functions that you should probably create
 *   * checkForWin - checks to see If a player has won or the game Is a draw
 *   * drawboard — redraws the board for each player turn
 *   * markBoard - sets the char array with a selection and check for an invalid
 *     selection
 */
#include <stdarg.h>
#include <stdio.h>

#define BOARD_SIZE 110

int check_for_win(char *board);
void draw_board(char *board);
void mark_board(int player, char *board, char *print_board);

int main() {
  int player_win = 0;
  int i;
  int rounds;
  char board[10] = "0123456789";
  char print_board[BOARD_SIZE] =
      "\n   |   |   \n 1 | 2 | 3 \n___|___|___\n   |   |   \n 4 | 5 | "
      "6 \n___|___|___\n   |   |   \n 7 | 8 | 9 \n   |   |   \n";

  do {
    draw_board(print_board);

    for (i = 1; i < 3; ++i) {
      mark_board(i, board, print_board);
      player_win = check_for_win(board);
      draw_board(print_board);
      ++rounds;

      if (player_win != 0)
        break;
      if (rounds == 9) {
        printf("It's a draw match!\n");
        return 0;
      }
    }
  } while (player_win == 0);

  printf("Player %i won!\n", player_win);
  return 0;
}

// Prints the tic-tac-toe board
void draw_board(char *board) {
  // Clear the terminal
  // reference:
  // https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c#:~:text=just%20type%20clrscr()%3B%20function,function%20easy%20to%20clear%20screen.
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  printf("\e[1;1H\e[2J");

  // Prints the board
  int i;
  printf("      TIC TAC TOE\n\n      (X) Player 1\n      (O) Player 2\n");
  for (i = 0; i < BOARD_SIZE; ++i) {
    printf("%c ", board[i]);
  }
  printf("\n");
}

// Marks the player's position in board
void mark_board(int player, char *board, char *print_board) {
  int player_position;

  printf("Player %d, enter your position: ", player);
  scanf("%i", &player_position);

  if (board[player_position] == 'X' || board[player_position] == 'O') {
    printf("Position taken already. Pick another one\n");
    mark_board(player, board, print_board);
  } else
    board[player_position] = player == 1 ? 'X' : 'O';

  if (player_position == 1)
    print_board[14] = board[player_position];
  else if (player_position == 2)
    print_board[18] = board[player_position];
  else if (player_position == 3)
    print_board[22] = board[player_position];
  else if (player_position == 4)
    print_board[50] = board[player_position];
  else if (player_position == 5)
    print_board[54] = board[player_position];
  else if (player_position == 6)
    print_board[58] = board[player_position];
  else if (player_position == 7)
    print_board[86] = board[player_position];
  else if (player_position == 8)
    print_board[90] = board[player_position];
  else if (player_position == 9)
    print_board[94] = board[player_position];
  else {
    printf("Invalide position. Pick another one\n");
    mark_board(player, board, print_board);
  }
}

// Check if the board's indices(checker) are equal
int check_eql_board(char *board, int *checker) {
  int eql = 0;

  if (board[checker[0]] == board[checker[1]] &&
      board[checker[1]] == board[checker[2]])
    eql = board[checker[0]] == 'X' ? 1 : 2;

  return eql;
}

// Checks if a player win the game
int check_for_win(char *board) {
  int player_win = 0;
  int checker[8][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7},
                       {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {7, 5, 3}};
  int i;
  for (i = 0; i < 8; ++i) {
    player_win = check_eql_board(board, checker[i]);
    if (player_win != 0)
      break;
  }

  return player_win;
}
