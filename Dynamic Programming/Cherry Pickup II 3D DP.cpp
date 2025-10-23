#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution
{
private:
    int helper(int row, int col1, int col2, vector<vector<int>> &grid)
    {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
            return -1e8; // Invalid Move
        if (row == grid.size() - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        int maxi = INT_MIN;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int next = helper(row + 1, col1 + i, col2 + j, grid);
                int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                maxi = max(maxi, curr + next);
            }
        }
        return maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return helper(0, 0, n - 1, grid);
    }
};

class Solution
{
    // Using Memoization
private:
    int helper(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<ll>>> &dp)
    {
        if (col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
            return -1e8;
        if (row == grid.size() - 1)
        {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int delCol[] = {-1, 0, 1};
        int maxi = INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int next = helper(row + 1, col1 + delCol[i], col2 + delCol[j], grid, dp);
                int curr = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                maxi = max(maxi, curr + next);
            }
        }
        return dp[row][col1][col2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(n, -1)));
        return helper(0, 0, n - 1, grid, dp);
    }
};

class Solution
{
    // Using Tabulation
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>>(n, vector<ll>(n, 0)));
        // Base Case for last row
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                dp[m - 1][j1][j2] = (j1 == j2) ? grid[m - 1][j1] : grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        // Writing all states

        for (int r = m - 2; r >= 0; r--)
        {
            for (int c1 = 0; c1 < n; c1++)
            {
                for (int c2 = 0; c2 < n; c2++)
                {
                    ll maxi = LLONG_MIN;
                    for (int dc1 = -1; dc1 <= 1; dc1++)
                    {
                        for (int dc2 = -1; dc2 <= 1; dc2++)
                        {
                            ll value = 0;
                            if (c1 == c2)
                                value = grid[r][c1];
                            else
                                value = grid[r][c1] + grid[r][c2];
                            if (c1 + dc1 >= 0 && c1 + dc1 < n && c2 + dc2 >= 0 && c2 + dc2 < n)
                                value += dp[r + 1][c1 + dc1][c2 + dc2];
                            else
                                value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    dp[r][c1][c2] = maxi;
                }
            }
        }
        return dp[0][0][n - 1];
    }
};

class Solution
{
    // Using  optimised Tabulation
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> front(n, vector<int>(n, 0));
        // Base Case for last row
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                front[j1][j2] = (j1 == j2) ? grid[m - 1][j1] : grid[m - 1][j1] + grid[m - 1][j2];
            }
        }
        // Writing all states

        for (int r = m - 2; r >= 0; r--)
        {
            vector<vector<int>> cur(n, vector<int>(n, 0));
            for (int c1 = 0; c1 < n; c1++)
            {
                for (int c2 = 0; c2 < n; c2++)
                {
                    ll maxi = LLONG_MIN;
                    for (int dc1 = -1; dc1 <= 1; dc1++)
                    {
                        for (int dc2 = -1; dc2 <= 1; dc2++)
                        {
                            ll value = 0;
                            if (c1 == c2)
                                value = grid[r][c1];
                            else
                                value = grid[r][c1] + grid[r][c2];
                            if (c1 + dc1 >= 0 && c1 + dc1 < n && c2 + dc2 >= 0 && c2 + dc2 < n)
                                value += front[c1 + dc1][c2 + dc2];
                            else
                                value += -1e8;
                            maxi = max(maxi, value);
                        }
                    }
                    cur[c1][c2] = maxi;
                }
            }
            front = cur;
        }
        return front[0][n - 1];
    }
};