#include <bits/stdc++.h>
using namespace std;
class Solution
{
    const int M = 1e9 + 7;

public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // adjacency list: node -> {neighbor, weight}
        vector<pair<int, int>> adj[n];
        for (auto &it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> time(n, 1e18); // distance
        vector<long long> ways(n, 0);    // number of ways
        time[0] = 0;
        ways[0] = 1;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0}); // {time, node}

        while (!pq.empty())
        {
            long long mins = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip if this is not the shortest dist anymore
            if (mins > time[node])
                continue;

            for (auto &it : adj[node])
            {
                int adjNode = it.first;
                long long edgeWt = it.second;

                if (time[adjNode] > mins + edgeWt)
                {
                    time[adjNode] = mins + edgeWt;
                    pq.push({time[adjNode], adjNode});
                    ways[adjNode] = ways[node]; // inherit count
                }
                else if (time[adjNode] == mins + edgeWt)
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % M;
                }
            }
        }

        return ways[n - 1] % M;
    }
};