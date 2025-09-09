#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            if (dfs(nbr, node, adj, vis)) return true;
        } else if (nbr != parent) {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,4},{4,0}};
    cout << (isCycle(V, edges) ? "true" : "false") << endl;
    return 0;
}
