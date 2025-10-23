#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // using Memoization
    int helper(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + helper(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));
    }

public:
    int shortestCommonSupersequence(string &s1, string &s2)
    {
        // Using Index Shifting Technique
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return n + m - helper(n, m, s1, s2, dp);
    }
};



class Solution
{
//using Tabulation
public:
   
    int shortestCommonSupersequence(string &s1, string &s2)
    {
        // Using Index Shifting Technique
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return n + m - dp[n][m];
    }
};