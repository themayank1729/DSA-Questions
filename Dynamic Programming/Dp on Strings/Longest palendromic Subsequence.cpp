#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int helper(int i, int j, string &s)
    {
        if (i == j)
        {
            return 1;
        }
        if (i > j)
            return 0;

        if (s[i] == s[j])
        {
            return 2 + helper(i + 1, j - 1, s);
        }
        return max(helper(i + 1, j, s), helper(i, j - 1, s));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        return helper(0, n - 1, s);
    }
};

class Solution
{
    // using Memoization  by Mayank
private:
    int helper(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (i == j)
        {
            return 1;
        }
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
        {
            return dp[i][j] = 2 + helper(i + 1, j - 1, s, dp);
        }
        return dp[i][j] = max(helper(i + 1, j, s, dp), helper(i, j - 1, s, dp));
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp);
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int ind1 = text1.size();
        int ind2 = text2.size();
        vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0));
        for (int i = 0; i <= ind1; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= ind2; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= ind1; i++)
        {
            for (int j = 1; j <= ind2; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[ind1][ind2];
    }
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};

// auto init = atexit([]()
//                    { ofstream("display_runtime.txt") << "0"; });
