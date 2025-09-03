#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void bfs(int row, int col, vector<vector<bool>> &visited, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        visited[row][col] = true;

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int deltaRow = -1; deltaRow <= 1; deltaRow++)
            {
                for (int deltaCol = -1; deltaCol <= 1; deltaCol++)
                {
                    int neighborRow = row + deltaRow;
                    int neighborCol = col + deltaCol;
                    if (neighborCol >= 0 && neighborRow >= 0 && neighborRow < n && neighborCol < m) // for valid  rows and columns
                    {
                        if (!visited[neighborRow][neighborCol] && grid[neighborRow][neighborCol] == '1')
                        {
                            q.push({neighborRow, neighborCol});
                            visited[neighborRow][neighborCol] = 1;
                        }
                    }
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, 0));

        int count = 0;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < m; col++)
            {
                if (!visited[row][col] && grid[row][col] == '1')
                {
                    count++;
                    bfs(row, col, visited, grid);
                }
            }
        }
        return count;
    }
};