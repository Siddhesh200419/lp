#include <iostream>
using namespace std;

#define N 4  // Size of the chessboard (4x4)

// These arrays help us apply constraints (bound step)
bool column[N];           // Tracks if a column has a queen
bool diagLeft[2 * N];     // Tracks \ diagonals (row - col + N - 1)
bool diagRight[2 * N];    // Tracks / diagonals (row + col)
int board[N][N];          // Chessboard (1 = queen, 0 = empty)

// Function to solve N-Queens using branch and bound
bool placeQueen(int row) {
    // Base case: all rows are filled
    if (row == N)
        return true;

    // Try placing a queen in each column of this row
    for (int col = 0; col < N; col++) {
        // Check if it's safe to place a queen at (row, col)
        if (!column[col] && !diagLeft[row - col + N - 1] && !diagRight[row + col]) {
            // Place the queen
            board[row][col] = 1;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = true;

            // Recur to place queen in the next row
            if (placeQueen(row + 1))
                return true;

            // Backtrack: remove queen and reset constraints
            board[row][col] = 0;
            column[col] = diagLeft[row - col + N - 1] = diagRight[row + col] = false;
        }
    }

    // If no column in this row is valid, return false
    return false;
}

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main() {
    // Initialize all arrays and board to false/0
    for (int i = 0; i < N; i++) column[i] = false;
    for (int i = 0; i < 2 * N; i++) diagLeft[i] = diagRight[i] = false;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    // Start placing queens from row 0
    if (placeQueen(0))
        printBoard();
    else
        cout << "No solution found.\n";

    return 0;
}
