#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // n  - total number of vertices
        // m - total number of edges
        vector<pair<int, int>> adj[n + 1]; // 1 based indexing

        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
        dist[1] = 0; // source is one
        pq.push({0, 1});
        while (!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;

            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;
                if (dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        if (dist[n] == 1e9)
            return {-1};
        vector<int> path;
        int node = n; // where n is coming from
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);
        return path;
    }
};
// for gfg