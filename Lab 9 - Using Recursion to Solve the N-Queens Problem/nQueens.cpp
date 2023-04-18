/*
 * Name: Russell Welch
 * Date Submitted: 04/18/23
 * Lab Section: 001
 * Assignment Name: Lab 9 - Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

// This function checks if a queen can be placed in a given position (row, col)
// without attacking any other queens that have already been placed.
bool canPlaceQueen(const vector<int>& placedQueens, int row, int col) {
    for (int i = 0; i < col; i++) {
        if (placedQueens[i] == row || abs(placedQueens[i] - row) == abs(i - col)) {
            return false;
        }
    }
    return true;
}

// This is a recursive helper function that finds all the possible solutions to the problem.
// It takes a vector of placed queens, the current column, a reference to the solution count, and the board size (n).
void findSolutions(vector<int>& placedQueens, int col, int& solutionCount, int n) {
    if (col == n) {
        solutionCount++;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (canPlaceQueen(placedQueens, row, col)) {
            placedQueens[col] = row;
            findSolutions(placedQueens, col + 1, solutionCount, n);
        }
    }
}

// This function calculates the number of solutions for placing n queens on an nxn chessboard.
int nQueens(int n) {
    vector<int> placedQueens(n, -1);
    int solutionCount = 0;
    findSolutions(placedQueens, 0, solutionCount, n);
    return solutionCount;
}

// int main()
// {
//     cout << "1: " << nQueens(1) << endl;
//     cout << "2: " << nQueens(2) << endl;
//     cout << "3: " << nQueens(3) << endl;
//     cout << "4: " << nQueens(4) << endl;
//     cout << "5: " << nQueens(5) << endl;
//     cout << "6: " << nQueens(6) << endl;
//     cout << "7: " << nQueens(7) << endl;
//     cout << "8: " << nQueens(8) << endl;
//     cout << "9: " << nQueens(9) << endl;
//     cout << "10: " << nQueens(10) << endl;
//     cout << "11: " << nQueens(11) << endl;
//     cout << "12: " << nQueens(12) << endl;
//     return 0;
// }