# Tic-Tac-Toe-with-Min-Max-Algorithm
Making of Tic Tac Toe Game with AI Algorithm(Min Max Algorithm)
Tic-Tac-Toe AI

Description

This project is a simple Tic-Tac-Toe game where the player competes against an AI opponent. The AI utilizes the Minimax algorithm to make optimal moves and is unbeatable. The game is played on a 3x3 grid, and the user plays as 'O' while the AI plays as 'X'.

Features

AI using Minimax Algorithm: Ensures optimal moves every turn.

Human vs AI Gameplay: The user can choose to play first or let the AI start.

Intelligent Move Selection: AI predicts the best move to maximize its chances of winning.

Game Status Detection: Checks for a win, loss, or tie.

How the Code Works

1. Board Representation

The game board is represented as a 3x3 grid using a vector<vector<char>>. Each cell can be:

'O' - Human player

'X' - AI player

'_' - Empty space

2. Checking for a Winner

The checkWinner() function scans rows, columns, and diagonals to determine if either player has won. If no moves are left and no one has won, it returns 'T' for a tie.

3. Minimax Algorithm

The minimax(bool isMaximizing) function:

Recursively evaluates all possible game states.

Assigns scores (+10 for AI win, -10 for human win, 0 for tie).

Chooses the best possible move for AI while assuming the human also plays optimally.

4. AI Move Selection

The bestMove() function:

Iterates through available moves.

Uses Minimax to evaluate the outcome of each move.

Chooses the move that maximizes AI's chances of winning.

5. Game Loop

The main() function:

Allows the user to decide whether to play first.

Continuously alternates turns between the user and AI.

Ends the game when there is a winner or a tie.

How to Play

Compile and run the ai.cpp file.

Choose whether you want to play first (y/n).

Enter your move as row and column indices (0-2).

The AI will automatically respond with the best possible move.

The game continues until either the player or AI wins, or the board is full (tie).

Compilation and Execution

Compile the code using g++:

 g++ ai.cpp -o tic_tac_toe

Run the executable:

 ./tic_tac_toe

Example Gameplay

Tic Tac Toe: You (O) vs AI (X)
. . .
. . .
. . .
Do you want to go first? (y/n): y
Enter your move (row and column: 0-2): 0 0
O . .
. . .
. . .
AI's move:
O . .
. X .
. . .

Future Improvements

Implementing Alpha-Beta Pruning for better efficiency.

Adding a GUI version using SDL or OpenGL.

Allowing different difficulty levels.

License

This project is open-source and free to use for educational purposes.

