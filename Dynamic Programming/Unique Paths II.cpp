#include <bits/stdc++.h>
using namespace std;
class Solution
{ // Using Recursion
private:
    int helper(int m, int n, vector<vector<int>> &grid)
    {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (grid[m][n] == 1)
            return 0;
        return helper(m - 1, n, grid) + helper(m, n - 1, grid);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        return helper(m - 1, n - 1, obstacleGrid);
    }
};
class Solution
{

    // Using memoization
private:
    int helper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (grid[m][n] == 1)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = helper(m - 1, n, grid, dp) + helper(m, n - 1, grid, dp);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, obstacleGrid, dp);
    }
};
class Solution
{
    // Using tabulation

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    if (obstacleGrid[i][j] == 0)
                    {
                        if (i > 0)
                            dp[i][j] = dp[i - 1][j];
                        if (j > 0)
                            dp[i][j] += dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution
{
    // Space optimising the  tabulation method
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    cur[j] = 1;
                else if (obstacleGrid[i][j] == 0)
                {

                    cur[j] = prev[j];
                    if (j > 0)
                        cur[j] = cur[j] + cur[j - 1];
                }
                else
                {
                    cur[j] = 0;
                }
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};