#include <bits/stdc++.h>
using namespace std;
class Solution
{ // using Recursion
    bool helper(int i, int j, const string &s1, const string &s2)
    {

        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (j >= 0 && i < 0)
        {
            while (j != -1) // looping from 0 to j -> [0,j]
            {
                if (s2[j--] != '*')
                    return false;
            }
            return true;
        }

        if (s1[i] == s2[j] || s2[j] == '?')
            return helper(i - 1, j - 1, s1, s2);
        if (s2[j] == '*')
            return helper(i - 1, j, s1, s2) | helper(i, j - 1, s1, s2);
        return false;
    }

public:
    bool isMatch(string s, string p)
    {

        int n = s.size();
        int m = p.size();
        return helper(n - 1, m - 1, s, p);
    }
};

class Solution
{
    // using Memoization and  Index shifting
    bool helper(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp)
    {

        if (i == 0 && j == 0)
            return true;
        if (j == 0 && i > 0)
            return false;
        if (j > 0 && i == 0)
        {
            for (int ind = 1; ind <= j; ind++)
            {
                if (s2[ind - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j] == 1;
        if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '?')
            return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp) ? 1 : 0;
        if (s2[j - 1] == '*')
            return dp[i][j] = helper(i - 1, j, s1, s2, dp) || helper(i, j - 1, s1, s2, dp) ? 1 : 0;
        return false;
    }

public:
    bool isMatch(string s, string p)
    {

        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, s, p, dp);
    }
};

class Solution
{
    // Using Tabulation
public:
    bool isMatch(string text, string pattern)
    {

        int n = text.size();
        int m = pattern.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for (int j = 1; j <= pattern.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (pattern[j - 1] == '*')

                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

class Solution
{
    // Using Tabulation using 2 arrays
public:
    bool isMatch(string text, string pattern)
    {

        int n = text.size();
        int m = pattern.size();

        vector<bool> prev(m + 1, false);
        prev[0] = true;

        for (int j = 1; j <= pattern.size(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
            {
                if (pattern[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }

        for (int i = 1; i <= n; i++)
        {
            vector<bool> cur(m + 1, false);
            for (int j = 1; j <= m; j++)
            {
                if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
                    cur[j] = prev[j - 1];
                else if (pattern[j - 1] == '*')

                    cur[j] = cur[j - 1] | prev[j];
                else
                    cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    }
};

class Solution
{ // strivers
    bool isAllStars(string &S1, int i)
    {
        // S1 is taken in 1-based indexing
        for (int j = 1; j <= i; j++)
        {
            if (S1[j - 1] != '*')
                return false;
        }
        return true;
    }

    bool wildcardMatching(string &S1, string &S2)
    {
        int n = S1.size();
        int m = S2.size();

        vector<bool> prev(m + 1, false);
        vector<bool> cur(m + 1, false);

        prev[0] = true; // Initialize the first element of the previous row to true

        for (int i = 1; i <= n; i++)
        {
            cur[0] = isAllStars(S1, i); // Initialize the first element of the current row
            for (int j = 1; j <= m; j++)
            {
                if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                {
                    cur[j] = prev[j - 1];
                }
                else
                {
                    if (S1[i - 1] == '*')
                    {
                        cur[j] = prev[j] || cur[j - 1];
                    }
                    else
                    {
                        cur[j] = false;
                    }
                }
            }
            prev = cur;
        }

        return prev[m];
    }
};