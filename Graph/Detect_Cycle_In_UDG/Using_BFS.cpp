#include <bits/stdc++.h>
using namespace std;

bool isCycleBFS(vector<int> adj[], int u, vector<bool> &visited)
{
    queue<pair<int, int>> q;
    q.push({u, -1});
    visited[u] = true;
    while (!q.empty())
    {
        int source = q.front().first;
        int parent = q.front().second;

        q.pop();
        for (int &v : adj[source])
        {
            if (!visited[v])
            {
                q.push({v, source});
            }
            else if (v != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleBFS(adj, i, visited))
            return true;
    }
    return false;
}