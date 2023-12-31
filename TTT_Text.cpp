#include <stdlib.h>
#include <ios>
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player = 'X';
char location;
char gameState = 'W';

void renderBoard() {
  cout << "\n";
  cout << "\t\t\t   TIC TAC TOE\n";
  cout << "\t\t PLAYER - 1 [X]  PLAYER - 2 [O]\n\n";
  cout << "\t\t          |          |\n";
  cout << "\t\t     " << board[0][0] << "    |    " << board[0][1] << "     |    " << board[0][2] << "     \n";
  cout << "\t\t          |          |\n";
  cout << "\t\t ---------|----------|---------\n";
  cout << "\t\t          |          |\n";
  cout << "\t\t     " << board[1][0] << "    |    " << board[1][1] << "     |    " << board[1][2] << "     \n";
  cout << "\t\t          |          |\n";
  cout << "\t\t ---------|----------|---------\n";
  cout << "\t\t          |          |\n";
  cout << "\t\t     " << board[2][0] << "    |    " << board[2][1] << "     |    " << board[2][2] << "     \n";
  cout << "\t\t          |          |\n";
}

bool gameOver() {  // check all combinations of gamestate --- true means game over, false means game should continue
  // verticals and horizontals
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
      return true;
    } else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
      return true;
    }
  }

  // diagonals
  if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2]) {
    return true;
  }

  // check if spaces remain, if no space is found, game is tied and over.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (isdigit(board[i][j])) {
        return false;
      }
    }
  }
  gameState = 'T';
  return true;
}

void playerTurn() {
  bool validInput = false;

  while (!validInput) {
    if (player == 'X') {
      cout << "[PLAYER 1] TURN: ";
    } else {
      cout << "[PLAYER 2] TURN: ";
    }

    cin >> location;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (cin.gcount() < 2 && location >= '1' && location <= '9') {  // get user input
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          if (board[i][j] == location) {
            validInput = true;
            board[i][j] = player;
            player = (player == 'X') ? 'O' : 'X';
          }
        }
      }
      if (!validInput) {
        cout << "This location is already taken. Please try again\n";
      }
    } else {
      cout << "Invalid input. Please try again.\n";
    }
  }
}

int main() {
  renderBoard();
  while (!gameOver()) {
    playerTurn();
    renderBoard();
  }

  cout << "\t\t\t    GAME OVER\n";
  if (gameState == 'W') {
    if (player == 'O') {  // if it was O's turn and the game ended, that means X won (and vice versa)
      cout << "\t\t\t  PLAYER 1 WINS";
    } else {
      cout << "\t\t\t  PLAYER 2 WINS";
    }
  } else {
    cout << "\t\t\t    GAME TIED\n";
  }
}
