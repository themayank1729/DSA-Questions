#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // using recursion
private:
    int helper(int i, int j, const string &s1, const string &s2)
    {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        if (s1[i] == s2[j])
            return helper(i - 1, j - 1, s1, s2);
        else
            return min({1 + helper(i, j - 1, s1, s2), 1 + helper(i - 1, j, s1, s2), 1 + helper(i - 1, j - 1, s1, s2)});
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return helper(n - 1, m - 1, word1, word2);
    }
};
class Solution
{
    // using Memoization & Index Shifting
private:
    int helper(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        if (j == 0)
            return i;
        if (i == 0)
            return j;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
        else
            return dp[i][j] = min({1 + helper(i, j - 1, s1, s2, dp), 1 + helper(i - 1, j, s1, s2, dp), 1 + helper(i - 1, j - 1, s1, s2, dp)});
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(n, m, word1, word2, dp);
    }
};

class Solution
{
    // using Tabulation & Index Shifting
private:
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int row = 0; row <= m; row++)
            dp[0][row] = row; // s1 is empty
        for (int col = 0; col <= n; col++)
            dp[col][0] = col; // s2 is empty

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({1 + dp[i][j - 1], 1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]});
            }
        }
        return dp[n][m];
    }
};

class Solution
{
    // Using Tabualtion with 2 arrays
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<int> prev(m + 1, 0);

        for (int row = 0; row <= m; row++)
            prev[row] = row; // s1 is empty

        for (int i = 1; i <= n; i++)
        {
            vector<int> cur(m + 1, 0);
            cur[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = prev[j - 1];
                else
                    cur[j] = 1 + min({cur[j - 1], prev[j], prev[j - 1]});
                // min({insert,delete,replace})
            }
            prev = cur;
        }
        return prev[m];
    }
};
