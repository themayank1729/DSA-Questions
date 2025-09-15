#include <bits/stdc++.h>
using namespace std;
// User function Template for C++
// User function Template for C++
class Solution
{
public:
    int findCity(int n, int m, vector<vector<int>> &edges, int dis)
    {

        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    dist[i][j] = 0;
            }
        }

        for (auto it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] != 1e8 && dist[k][j] != 1e8 && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int finalMinCityCount = n;
        int minCityCount = 0;
        int largeCity = 0;
        for (int i = 0; i < n; i++)
        {
            minCityCount = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= dis)
                {
                    minCityCount++;
                }
            }
            if (finalMinCityCount >= minCityCount)
            {
                finalMinCityCount = minCityCount;
                largeCity = i;
            }
        }
        return largeCity;
    }
};
