#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // using Recursion
private:
    int helper(int i, int j, vector<int> &arr, int n)
    {
        if (i == j)
            return 0;
        int mini = 1e9;
        for (int k = i; k < j; k++)
        // we are going till k < j because we are calling for k+1
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + helper(i, k, arr, n) + helper(k + 1, j, arr, n);
            mini = min(mini, steps);
        }
        return mini;
    }

public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        int i = 1;
        int j = n - 1;

        helper(i, j, arr, n);
    }
};

class Solution
{
    // Using Memoization
private:
    int helper(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int k = i; k < j; k++)
        // we are going till k < j because we are calling for k+1
        {
            int steps = (arr[i - 1] * arr[k] * arr[j]) + helper(i, k, arr, n, dp) + helper(k + 1, j, arr, n, dp);
            mini = min(mini, steps);
        }
        return dp[i][j] = mini;
    }

public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        int i = 1;
        int j = n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(i, j, arr, n, dp);
    }
};

class Solution
{
    // Using Tabulation
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (int cl = 2; cl < n; cl++)
        {
            for (int i = 1; i <= n - cl; i++)
            {
                int j = i + cl - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }
};