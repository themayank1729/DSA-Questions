// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    const int mod = 1e5;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {

        vector<int> dist(1e5 - 1, 1e9);
        queue<pair<int, int>> q; // node, steps
        q.push({start, 0});
        dist[start] = 0;

        while (!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (node == end)
                return steps;
            for (int it : arr)
            {
                int newNode = (node % mod * it % mod) % mod;
                if (dist[newNode] == 1e9)
                { // we will only push if it is unvisited else we wont push so that q wont get filled with unnecessary calculations and also to avoid infinite loop because if we wont check if it is visited and just goes onj pushing elements and if the target node is unreachable then it will lead to infinity
                    q.push({newNode, steps + 1});
                    dist[newNode] = steps + 1;
                }
            }
        }
        if (dist[end] == 1e9)
            return -1;
        return dist[end];
    }
};