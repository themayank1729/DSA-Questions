
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        int row = source.first;
        int col = source.second;

        // what if we are standing on destination == source  // edge case
        if (row == destination.first && col == destination.second)
            return 0;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[row][col] = 0;

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {row, col}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            /*
            or
            if (row == destination.first && col == destination.second)
                            return dis;
            */
            for (int i = 0; i < 4; i++)
            {
                int adjRow = row + delRow[i];
                int adjCol = col + delCol[i];
                if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < m && grid[adjRow][adjCol] == 1)
                {

                    if (dist[adjRow][adjCol] > dis + 1)
                    {
                        if (adjRow == destination.first && adjCol == destination.second)
                            return dis + 1;
                        q.push({dis + 1, {adjRow, adjCol}});
                        dist[adjRow][adjCol] = dis + 1;
                    }
                }
            }
        }
        return -1;
    }
};
