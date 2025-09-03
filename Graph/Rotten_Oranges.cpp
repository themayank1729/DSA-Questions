#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int countFresh = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (grid[row][col] == 2)
                {
                    q.push({{row, col}, 0});
                    visited[row][col] = 2;
                }
               
                if (grid[row][col] == 1)
                    countFresh++;
            }
        }
        int tm = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int cnt = 0;
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size())
                {
                    if (grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
                    {
                        q.push({{nrow, ncol}, t + 1});
                        visited[nrow][ncol] = 2;
                        cnt++;
                    }
                }
            }
        }
        if (cnt != countFresh)
            return -1;
        return tm;
    }
};