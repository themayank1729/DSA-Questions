#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
    int helper(int ind1, int ind2, const string &s1, const string &s2)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (s1[ind1] == s2[ind2])
            return 1 + helper(ind1 - 1, ind2 - 1, s1, s2);

        return max(helper(ind1 - 1, ind2, s1, s2), helper(ind1, ind2 - 1, s1, s2));
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        return helper(n1 - 1, n2 - 1, s1, s2);
    }
};

class Solution
{
    // Using Memoization
    int helper(int ind1, int ind2, const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + helper(ind1 - 1, ind2 - 1, s1, s2, dp);

        return dp[ind1][ind2] = max(helper(ind1 - 1, ind2, s1, s2, dp), helper(ind1, ind2 - 1, s1, s2, dp));
    }

public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return helper(n1 - 1, n2 - 1, s1, s2, dp);
    }
};

class Solution
{
    // using Tabulation   -- Mayank
public:
    int longestCommonSubsequence(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else // Unmatched and then skipping one character
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};