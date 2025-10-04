#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
    int helper(int m, int n, vector<vector<int>> &grid)
    {
        if (m == 0 && n == 0)
            return grid[0][0];
        if (m < 0 || n < 0) // we reached some point which is not the destination so we are returning that big number such that we are not even going to comapre this path so we are returning 1e9 because we are not at destination so we are not counting this as a sum.
            return 1e9;

        int leftSum = grid[m][n] + helper(m, n - 1, grid);
        int upSum = grid[m][n] + helper(m - 1, n, grid);

        return min(leftSum, upSum);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return helper(m - 1, n - 1, grid);
    }
};








class Solution
{
    // using Memoization
    int helper(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return grid[0][0];
        if (m < 0 || n < 0)
            return 1e9;
        if (dp[m][n] != -1)
            return dp[m][n];
        int leftSum = grid[m][n] + helper(m, n - 1, grid, dp);
        int upSum = grid[m][n] + helper(m - 1, n, grid, dp);

        return dp[m][n] = min(leftSum, upSum);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, grid, dp);
    }
};











class Solution
{
    // Using tabulation

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = 1e9, left = 1e9;
                if (i == 0 && j == 0)
                    dp[0][0] = grid[i][j];
                else
                {
                    if (i > 0)
                        up = grid[i][j] + dp[i - 1][j];
                    if (j > 0)
                        left = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};



class Solution
{
    //Optimised tabulation  

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
   

         vector<int>prev(n,0);
         prev[0]  = grid[0][0];
   
     for (int col = 1; col < n; col++)
     {
        prev[col] = prev[col-1] + grid[0][col];
     
     }
    
     
        for (int i = 1; i < m; i++)
        {
            vector<int>cur(n,0);
            int up = 1e9,left = 1e9;
            for (int j = 0; j < n; j++)
            {
                
                if(i > 0)  up = grid[i][j] +  prev[j];
                if(j > 0)  left = grid[i][j]  + cur[j-1];
                cur[j] = min(up,left);
            }
         
            prev = cur;
        }
        return prev[n-1];
    }
};