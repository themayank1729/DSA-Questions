#include <bits/stdc++.h>
using namespace std;
class Solution
{
    
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        //  V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

        vector<vector<int>> adj(V);
        // converting the edges vector into adjacency list which is adj
        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        vector<int>inDegree(V,0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
            
        }
        queue<int>q;
        for (int i = 0; i < V; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int>topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : adj[node])
            {
               inDegree[it]--;
               if(inDegree[it] == 0)q.push(it);
            }
            
        }
        return topo;
        
        
    }
};