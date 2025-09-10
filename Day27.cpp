#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    vector<vector<int>> adj(V);
    for(auto& e : edges) {
        adj[e].push_back(e[1]);
        adj[e[1]].push_back(e);
    }
    vector<int> dist(V, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[end];
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{2,3},{3,4}};
    int start = 0, end = 4;
    cout << shortestPath(V, edges, start, end);
    return 0;
}
