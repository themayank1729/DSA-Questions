#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {

        vector<pair<int, int>> adj[n];
        for (auto &e : flights)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt}); // it is directed graph
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}}); //{stops,{src,distance}}

        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edgeWt = iter.second;

                if (cost + edgeWt < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edgeWt;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};