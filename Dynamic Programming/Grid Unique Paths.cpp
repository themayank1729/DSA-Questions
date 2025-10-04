#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion  Mine
private:
    int helper(int x, int y, int m, int n)
    {
        if (x == m - 1 && y == n - 1)
        {
            return 1;
        }
        int count = 0;
        if (x + 1 < m)
            count += helper(x + 1, y, m, n);
        if (y + 1 < n)
            count += helper(x, y + 1, m, n);
        return count;
    }

public:
    int uniquePaths(int m, int n)
    {
        return helper(0, 0, m, n);
    }
};

class Solution
{
    // Using Recursion
    // Much Cleaner Recursion
    // Strivers
private:
    int helper(int m, int n, vector<vector<int>> &dp)
    {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;

        if (dp[m][n] != -1)
            return dp[m][n];
        return dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};

class Solution
{
    // Using tabulation
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = 0, left = 0;
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else
                {
                    if (i > 1)
                        up = dp[i - 1][j];
                    if (j > 1)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution
{
    // tabulation further optimisied
public:
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 1);

        for (int i = 1; i < m; i++)
        {
            vector<int> cur(n, 0);
            for (int j = 0; j < n; j++)
            {

                cur[j] = prev[j];
                if (j > 0)
                    cur[j] += cur[j - 1];
            }
            prev = cur;
        }
        return prev[n - 1];
    }
};

