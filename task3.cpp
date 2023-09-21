#include <iostream>
#include <vector>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check reverse diagonal
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; // If any empty cell is found, the game is not a draw
        }
    }
    return true; // All cells are filled, and there's no winner, so it's a draw
}

int main() {
    vector<vector<char> > board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    char currentPlayer = 'X'; // Start with player 'X'

    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameWon && !gameDraw) {
        // Display the current state of the board
        displayBoard(board);

        // Prompt the current player for their move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Update the board with the player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
                gameWon = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw! Good game!" << endl;
                gameDraw = true;
            } else {
                // Switch to the other player for the next turn
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    return 0;
}
