#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char HUMAN = 'O';
const char AI = 'X';
const char EMPTY = '_';

vector<vector<char>> board(3, vector<char>(3, EMPTY));

void printBoard() {
    for (const auto& row : board) {
        for (char cell : row)
            cout << (cell == EMPTY ? '.' : cell) << " ";
        cout << endl;
    }
    cout<< endl;
}

char checkWinner() {
  
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)//VERTICAL
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)//HORIZONTALIY
            return board[0][i];
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != EMPTY)
        return board[2][0];

    for (const auto& row : board)
        for (char cell : row)
            if (cell == EMPTY) return EMPTY;  

    return 'T';  
}

int minimax(bool isMaximizing) {
    char winner = checkWinner();
    if (winner == AI) return 10;
    if (winner == HUMAN) return -10;
    if (winner == 'T') return 0;

    int bestScore = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = isMaximizing ? AI : HUMAN;
                int score = minimax(!isMaximizing);
                board[i][j] = EMPTY;
                bestScore = isMaximizing ? max(bestScore, score) : min(bestScore, score);
            }
        }
    }
    return bestScore;
}

void bestMove() {
    int bestScore = numeric_limits<int>::min();
    int moveRow = -1, moveCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = AI;
                int score = minimax(false);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }
    board[moveRow][moveCol] = AI;
}

int main() {
    cout << "Tic Tac Toe: You (O) vs AI (X)\n";
    printBoard();

    char choice;
    cout << "Do you want to go first? (y/n): ";
    cin >> choice;

    bool isHumanTurn = (choice == 'y');
    while (true) {
        if (isHumanTurn) {
            int row, col;
            cout << "Enter your move (row and column: 0-2): ";
            cin >> row >> col;
            if (board[row][col] == EMPTY) {
                board[row][col] = HUMAN;
                printBoard();
                if (checkWinner() != EMPTY) break;
                isHumanTurn = false;
            } else {
                cout << "Invalid move. Try again.\n";
            }
        } else {
            bestMove();
            printBoard();
            if (checkWinner() != EMPTY) break;
            isHumanTurn = true;
        }
    }

    char result = checkWinner();
    if (result == 'T')
        cout << "It's a tie!\n";
    else
        cout << (result == AI ? "AI wins!" : "You win!") << endl;

    return 0;
}
