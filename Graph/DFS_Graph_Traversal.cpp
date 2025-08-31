#include <bits/stdc++.h>
using namespace std;

void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
{
    if (visited[u])
        return;
    visited[u] = true;
    result.push_back(u);

    for (int &v : adj[u])
    {
        if (!visited[v])
        {
            DFS(adj, v, visited, result);
        }
    }
}

vector<int> DFSOfGraph(int V, vector<int> mp[]) // V- > number of vertices and mp = [[2,3,1],[0],[0,4],[0],[2]]
{
    unordered_map<int, vector<int>> adj;
    for (int u = 0; u < V; u++)
    {
        for (auto v = mp[u].begin(); v != mp[u].end(); v++)
        {
            adj[u].push_back(*v);
        }
    }
    vector<int> result;
    vector<bool> visited(V, false);

    DFS(adj, 0, visited, result);
    return result;
}

