#include <bits/stdc++.h>
using namespace std;

// Google Maps - Shortest Path 
vector<int> dijkstra(unordered_map<int, unordered_map<int, int>>& graph, int start) {
    int V = graph.size();

    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;

        pq.pop();
        for (auto it : graph[node]) {
            int v = it.first;
            int w = it.second;
            if (dis + w < dist[v]) {
                dist[v] = dis + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int V, E;
    cout << "Welcome to Google Maps" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter the number of cities: ";
    cin >> V;
    cout << "Enter the total number of roads in the map: ";
    cin >> E;
    cout << endl;
    
    unordered_map<string, int> cityMap;
    unordered_map<int, string> reverseCityMap; 
    int cityInd = 0;

    cout << "Enter the path details for all the roads in the following format:" << endl;
    cout << "City1 City2 Distance" << endl;
    
    // Input cities and distances
    unordered_map<int, unordered_map<int, int>> graph;
    for (int i = 0; i < E; i++) {
        string city1, city2;
        int weight;
        cout << "Road " << i + 1 << ": ";
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

    string from, to;
    cout << "Enter the source city: ";
    cin >> from;
    cout << "Enter the destination city: ";
    cin >> to;
    cout << endl;
    
    if (cityMap.find(from) == cityMap.end() || cityMap.find(to) == cityMap.end()) {
        cout << "Invalid city names entered. Please try again." << endl;
        return 0;
    }

    vector<int> res = dijkstra(graph, cityMap[from]);
    cout << "The shortest distance from " << from << " to " << to << " is: " << res[cityMap[to]] << " units." << endl;
}
