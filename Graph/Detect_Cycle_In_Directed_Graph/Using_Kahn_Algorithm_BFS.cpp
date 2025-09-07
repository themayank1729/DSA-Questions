#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adj(V);
        // converting the edges vector into adjacency list which is 
        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        if (count == V)
            return false;
        else
            return true;
    }
};