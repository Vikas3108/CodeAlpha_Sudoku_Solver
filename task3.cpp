#include <iostream>
using namespace std;

// Define the size of the Sudoku grid
#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    cout << "----------------------------------------\n";
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            cout << "----------------------------------------\n";
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << " | ";
            }
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------\n";
}

// Function to check if a number can be placed in grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if num is already in the row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check if num is already in the column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check if num is already in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to find an empty cell (with value 0)
bool findEmptyCell(int grid[N][N], int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Recursive function to solve the Sudoku puzzle
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // If no empty cell is found, puzzle is solved
    if (!findEmptyCell(grid, row, col)) {
        return true;
    }

    // Try numbers 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if placing num is valid
        if (isSafe(grid, row, col, num)) {
            // Place the number
            grid[row][col] = num;

            // Recursively try to solve the rest of the puzzle
            if (solveSudoku(grid)) {
                return true;
            }

            // If placing num didn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // No valid number was found, trigger backtracking
    return false;
}

// Main function
int main() {
    // Sample Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Input Sudoku Puzzle:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku Puzzle:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists for the given puzzle.\n";
    }

    return 0;
}