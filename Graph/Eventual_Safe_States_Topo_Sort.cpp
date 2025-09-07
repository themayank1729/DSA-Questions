#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        // Reversing the graph edges
        vector<int> adjRev[V];
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            // it is a neighbor of i
            // i -> it (given)
            for (auto &it : adj[i])
            {
                adjRev[it].push_back(i);
                inDegree[i]++;
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
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for (auto it : adjRev[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
