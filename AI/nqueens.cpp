#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n) {
    int t_row = row;
    int t_col = col;

    while (row >= 0 and col >= 0) {
        if (board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = t_row;
    col = t_col;

    while (col >= 0) {
        if (board[row][col] == 'Q') return false;
        col--;
    }

    row = t_row;
    col = t_col;
    while (row < n and col >= 0) {
        if (board[row][col] == 'Q') return false;
        row++;
        col--;
    }
    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n) {
    if (col >= n) {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(i, col, board, n)) {
            board[i][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[i][col] = '.';
        }
    }
}

void solved(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal,
            vector<int> &upperDiagonal, int n) {
    if (col >= n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (leftRow[row] == 0 and lowerDiagonal[col + row] == 0 and upperDiagonal[n - 1 + col - row] == 0) {
            leftRow[row] = 1;
            lowerDiagonal[col + row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            board[row][col] = 'Q';
            solved(col + 1, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
            board[row][col] = '.';
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[col + row] = 0;
            leftRow[row] = 0;
        }
    }
}

vector<vector<string>> backTrack(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    solve(0, board, ans, n);
    return ans;
}

vector<vector<string>> branchNBound(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), lowerDiagonal(2 * n - 1, 0), upperDiagonal(2 * n - 1, 0);
    solved(0, board, ans, leftRow, lowerDiagonal, upperDiagonal, n);
    return ans;
}

void printArrangements(const vector<vector<string>> &arrangements) {
    for (int i = 0; i < arrangements.size(); i++) {
        cout << "Arrangement " << i + 1 << ":\n";
        for (int j = 0; j < arrangements[i].size(); j++) {
            cout << arrangements[i][j] << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> n;

    int choice;
    do {
        cout << "\nChoose an algorithm to solve the N-Queens problem:\n";
        cout << "1. Backtracking\n";
        cout << "2. Branch and Bound\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nSolving using Backtracking...\n";
                vector<vector<string>> backtrackingResult = backTrack(n);
                printArrangements(backtrackingResult);
                break;
            }
            case 2: {
                cout << "\nSolving using Branch and Bound...\n";
                vector<vector<string>> branchBoundResult = branchNBound(n);
                printArrangements(branchBoundResult);
                break;
            }
            case 0: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}
