#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVisited)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    for (int &v : adj[node])
    {
        if (!visited[v] && isCycleDFS(v, adj, visited, pathVisited))
        {
            return true;
        }
        else if (pathVisited[v])
            return true;
    }

    pathVisited[node] = 0;
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && isCycleDFS(i, adj, visited, pathVisited))
            return true;
    }
    return false;
}
