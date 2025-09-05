#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &pathVis, vector<int> &check)
    {
        visited[node] = 1;
        pathVis[node] = 1;
        // tarverse for adjacent nodes
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, adj, visited, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (pathVis[it] && visited[it])
            {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> visited(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> safeNodes;
        vector<int> check(V, 0); // to mark the node which is safe
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, pathVis, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }

        return safeNodes;
    }
};
