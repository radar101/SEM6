#include<bits/stdc++.h>
using namespace std;

// Rat in the maze
void solve(int row, int col, vector<vector<vector<char>>> &ans, vector<vector<char>>& grid, int n, vector<vector<int>>& visited) {
    if (row == n - 1 && col == n - 1) {
        ans.push_back(grid);
        return;
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int nextRow = row + drow[i];
        int nextCol = col + dcol[i];

        if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol] && grid[nextRow][nextCol] == '1') {
            visited[nextRow][nextCol] = 1;
            grid[nextRow][nextCol] = '#';
            solve(nextRow, nextCol, ans, grid, n, visited);
            visited[nextRow][nextCol] = 0;
            grid[nextRow][nextCol] = '1';
        }
    }
}

vector<vector<vector<char>>> findPath(vector<vector<char>>& grid, int n) {
    if (grid[0][0] == '0') {
        return {{}};
    }

    vector<vector<vector<char>>> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    visited[0][0] = 1;
    grid[0][0] = '#';
    solve(0, 0, ans, grid, n, visited);

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    cout << "Enter the elements of the grid (0 or 1):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<vector<char>>> paths = findPath(grid, n);

    cout << "Total Paths :" << paths.size() << endl;
    for (const auto& path : paths) {
        for (const auto& row : path) {
            for (char ch : row) {
                cout << ch << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
