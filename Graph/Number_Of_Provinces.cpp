#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &adjList, int node, vector<bool> &visited)
    {
        visited[node] = true;
        for (auto it : adjList[node])
        {
            if (!visited[it])
                dfs(adjList, it, visited);
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> adjList(V); // given is adjacency matrix and i am converting it to adjacency list

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> visited(V, false);
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(adjList, i, visited);
            }
        }
        return count;
    }
};