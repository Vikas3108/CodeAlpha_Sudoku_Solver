# CodeAlpha_Sudoku_Solver

Project OverviewThis repository contains a C++ program for a Sudoku Solver, developed as part of the CodeAlpha internship program (Task 3). The program solves a 9x9 Sudoku puzzle using a backtracking algorithm. It represents the puzzle as a 2D array, fills empty cells (marked as 0) with valid numbers (1–9) while adhering to Sudoku rules (no duplicates in rows, columns, or 3x3 subgrids), and displays both the input and solved grids. The program is efficient, user-friendly, and designed for console-based interaction, meeting the internship’s requirements for a robust solution.

Features
Sudoku Grid Representation: Uses a 9x9 2D array to represent the puzzle, with 0 indicating empty cells.
Backtracking Algorithm: Recursively fills empty cells with valid numbers, backtracking if a solution is not viable.
Sudoku Rule Validation: Ensures no duplicate numbers in rows, columns, or 3x3 subgrids before placing a number.
Formatted Output: Displays the input and solved grids with clear formatting, separating 3x3 subgrids for readability.
Error Handling: Detects and reports if a puzzle has no solution

Input Sudoku Puzzle:
----------------------------------------
5 3 0  | 0 7 0  | 0 0 0
6 0 0  | 1 9 5  | 0 0 0
0 9 8  | 0 0 0  | 0 6 0
----------------------------------------
8 0 0  | 0 6 0  | 0 0 3
4 0 0  | 8 0 3  | 0 0 1
7 0 0  | 0 2 0  | 0 0 6
----------------------------------------
0 6 0  | 0 0 0  | 2 8 0
0 0 0  | 4 1 9  | 0 0 5
0 0 0  | 0 8 0  | 0 7 9
----------------------------------------

Solved Sudoku Puzzle:
----------------------------------------
5 3 4  | 6 7 8  | 9 1 2
6 7 2  | 1 9 5  | 3 4 8
1 9 8  | 3 4 2  | 5 6 7
----------------------------------------
8 5 9  | 7 6 1  | 4 2 3
4 2 6  | 8 5 3  | 7 9 1
7 1 3  | 9 2 4  | 8 5 6
----------------------------------------
9 6 1  | 5 3 7  | 2 8 4
2 8 7  | 4 1 9  | 6 3 5
3 4 5  | 2 8 6  | 1 7 9
----------------------------------------
