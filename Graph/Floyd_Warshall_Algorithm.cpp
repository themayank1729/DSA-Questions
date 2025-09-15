// User function template for C++
#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution
{
public:
    void floydWarshall(vector<vector<int>> &cost)
    {

        // vector<vectror<int>> cost(dist.begin(),dist.end());
        int V = cost.size();
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {

                    if (cost[i][k] != (int)1e8 && cost[k][j] != (int)1e8 && cost[i][k] + cost[k][j] < cost[i][j])
                    {
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }
    }
};