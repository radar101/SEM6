#include <bits/stdc++.h>
using namespace std;

// Router reachable or not
vector<int> bfs(unordered_map<int, vector<int>>& graph, int start, int target) {
    unordered_set<int> visited;
    queue<pair<int, vector<int>>> q;
    
    q.push({start, {start}});
    visited.insert(start);

    while (!q.empty()) {
        int cur = q.front().first;
        vector<int> path = q.front().second;
        q.pop();

        if (cur == target) {
            return path; 
        }

        for (auto i : graph[cur]) {
            if (visited.find(i) == visited.end()) {
                vector<int> new_path = path; 
                new_path.push_back(i); 
                q.push({i, new_path});
                visited.insert(i);
            }
        }
    }

    return {}; 
}

int main() {
    int num_nodes;
    cout << "Enter the number of nodes: ";
    cin >> num_nodes;

    unordered_map<int, vector<int>> graph;

    cout << "Enter the graph edges (from_node to_node), enter -1 -1 to end input:\n";
    while (true) {
        int from, to;
        cin >> from >> to;
        if (from == -1 && to == -1) {
            break;
        }
        graph[from].push_back(to);
    }

    int start_node, target_node;
    cout << "Enter the start node: ";
    cin >> start_node;
    cout << "Enter the target node: ";
    cin >> target_node;

    vector<int> path = bfs(graph, start_node, target_node);

    if (!path.empty()) {
        cout << "Node " << target_node << " is reachable from Node " << start_node << "." << endl;
        cout << "Path: ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "Node " << target_node << " is not reachable from Node " << start_node << "." << endl;
    }

    return 0;
}
