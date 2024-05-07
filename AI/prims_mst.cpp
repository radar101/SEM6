#include <bits/stdc++.h>
using namespace std;

// Natural Gas Transport Line - Prim's MST
int primsMST(unordered_map<int, unordered_map<int,int>> &graph, int start, unordered_map<int, string> &reverseCityMap) {
    int v = graph.size();
    vector<bool> visited(v, false);
    vector<int> key(v, INT_MAX);
    vector<int> parent(v, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, start});
    key[start] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (auto p : graph[u]) {
            int weight = p.second;
            int v = p.first;
            if (!visited[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({weight, v});
            }
        }
    }

    int totalWeight = 0;
    cout << "The Lines having minimum costs are:" << endl;
    for (int i = 1; i < v; i++) {
        cout << reverseCityMap[parent[i]] << " - " << reverseCityMap[i] << " ----> " << graph[i][parent[i]] <<" Units"<< endl;
        totalWeight += graph[i][parent[i]];
    }
    return totalWeight;
}

int main() {
    int V, E;
    cout << "Welcome to ONGC - Natural Gas Transport System" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Enter the number of Cities: ";
    cin >> V;
    cout << "Enter the total number of gas transport lines: ";
    cin >> E;
    cout << endl;
    
    unordered_map<string, int> cityMap;
    unordered_map<int, string> reverseCityMap; 
    int cityInd = 0;

    cout << "Enter the details for all the lines in the following format:" << endl;
    cout << "City1 City2 Distance" << endl;
    
    // Input cities and distances
    unordered_map<int, unordered_map<int, int>> graph;
    for (int i = 0; i < E; i++) {
        string city1, city2;
        int weight;
        cout << "Line " << i + 1 << ": ";
        cin >> city1 >> city2 >> weight;

        int u, v;
        if (cityMap.find(city1) == cityMap.end()) {
            cityMap[city1] = cityInd;
            reverseCityMap[cityInd] = city1;
            u = cityInd;
            cityInd++;
        } else {
            u = cityMap[city1];
        }
        
        if (cityMap.find(city2) == cityMap.end()) {
            cityMap[city2] = cityInd;
            reverseCityMap[cityInd] = city2;
            v = cityInd;
            cityInd++;
        } else {
            v = cityMap[city2];
        }
        
        graph[u][v] = weight;
        graph[v][u] = weight;
    } 

    cout << endl;

    int mstWeight = primsMST(graph, 0, reverseCityMap);
    cout << "Total length of pipe line required is : " << mstWeight <<" units."<< endl;

    return 0;
}