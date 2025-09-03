#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> convert(vector<vector<int>> adj, int V)
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
    return adjList;
}