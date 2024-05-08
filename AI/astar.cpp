#include <bits/stdc++.h>
using namespace std;

// 8 Tile Puzzle
bool isValid(int x, int y)
{
    return x >= 0 and y >= 0 and x < 3 and y < 3;
}

int h(vector<vector<char>> &v, vector<vector<char>> &vv)
{
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (v[i][j] != vv[i][j])
                cnt++;
        }
    }
    return cnt;
}

int f(int h, int g) { return g + h; }

struct State
{
    vector<vector<char>> board;
    int g;
    int h;
    int f;
    int x;
    int y;

    State(vector<vector<char>> b, int g, int h, int x, int y) : board(b), g(g), h(h), x(x), y(y)
    {
        f = g + h;
    }

    // Overload the less than operator
    bool operator<(const State &other) const
    {
        return f > other.f; // Since we want the smallest f value to be at the top of the priority queue
    }
};

void solve(vector<vector<char>> &v, vector<vector<char>> &vv, int x, int y)
{
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(State(v, 0, h(v, vv), x, y));

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        cout << "Intermediate state:" << endl;
        cout << "f: " << current.f << ", g: " << current.g << ", h: " << current.h << endl;
        for (auto row : current.board)
        {
            for (auto cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
        cout << endl;

        if (current.board == vv)
        {
            cout << "Goal state reached!" << endl;
            return;
        }

        x = current.x;
        y = current.y;

        // Try moving the empty cell in all possible directions
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY))
            {
                vector<vector<char>> newBoard = current.board;
                swap(newBoard[x][y], newBoard[newX][newY]);
                int newH = h(newBoard, vv);
                int newG = current.g + 1;
                pq.push(State(newBoard, newG, newH, newX, newY));
            }
        }
    }

    cout << "Goal state not reachable!" << endl;
}

int main()
{
    vector<vector<char>> v(3, vector<char>(3)), vv(3, vector<char>(3));

    cout << "Enter initial state (use '_' for the empty tile):\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> v[i][j];
        }
    }

    cout << "Enter goal state:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> vv[i][j];
        }
    }

    int x, y;
    cout << "Enter the position of the empty tile (row and column indices, 0-based): ";
    cin >> x >> y;

    solve(v, vv, x, y);

    return 0;
}