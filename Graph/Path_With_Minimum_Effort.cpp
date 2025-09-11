#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 0;
        // {diff,{row,col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int mini = INT_MAX;
        while (!pq.empty())
        {
            int diff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return diff;

            for (int i = 0; i < 4; i++)
            {
                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];
                if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[adjRow][adjCol]), diff);
                    if (newEffort < dist[adjRow][adjCol])
                    {
                        dist[adjRow][adjCol] = newEffort;
                        pq.push({newEffort, {adjRow, adjCol}});
                    }
                }
            }
        }
        return 0; // unreachable
    }
};
