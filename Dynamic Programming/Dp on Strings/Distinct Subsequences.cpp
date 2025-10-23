#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
class Solution
{ // Using Recursion
    int helper(int i, int j, const string &s, const string &t)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j])
            return helper(i - 1, j - 1, s, t) + helper(i - 1, j, s, t);
        else
            return helper(i - 1, j, s, t);
    }

public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        return helper(n - 1, m - 1, s, t);
    }
};

class Solution
{ // Using Memozation  and Index Shifting
    int helper(int i, int j, const string &s, const string &t, vector<vector<int>> &dp)
    {
        if (j == 0) // it means -1 since we used index shifting so 0 == -1
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = helper(i - 1, j - 1, s, t, dp) + helper(i - 1, j, s, t, dp);
        else
            return dp[i][j] = helper(i - 1, j, s, t, dp);
    }

public:
    int numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, s, t, dp);
    }
};

class Solution
{

    // using Tabulation
public:
    ll numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1; // means t is empty dp[s][t]
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0; // means s is empty and t is non empty
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][m];
    }
};

class Solution
{
    // tabulation space optimisation by 2 arrays
public:
    ll numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        vector<ll> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            vector<ll> cur(m + 1, 0);
            cur[0] = 1;
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    cur[j] = prev[j - 1] + prev[j];
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        return prev[m];
    }
};

using ll = unsigned long long;
class Solution
{
    // using Single array Tabulation
public:
    ll numDistinct(string s, string t)
    {

        int n = s.size();
        int m = t.size();
        vector<ll> prev(m + 1, 0);
        prev[0] = 1;

        for (int i = 1; i <= n; i++)
        {

            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])
                    prev[j] = prev[j - 1] + prev[j];
                else /* you can comment the else part*/
                    prev[j] = prev[j];
            }
        }
        return prev[m];
    }
};