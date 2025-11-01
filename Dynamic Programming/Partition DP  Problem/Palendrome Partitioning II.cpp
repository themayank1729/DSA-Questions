#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // using Recursion
private:
    bool isPalendrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(int i, int j, string &s)
    {
        if (isPalendrome(i, j, s))
            return 0;
        if (i == j)
            return 0;

        int minCuts = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int cuts = 1 + helper(i, k, s) + helper(k + 1, j, s);
            minCuts = min(minCuts, cuts);
        }
        return minCuts;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        return helper(0, n - 1, s);
    }
};

class Solution
{
    // Using Memoization
private:
    bool isPalendrome(int i, int j, string &s)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if (isPalendrome(i, j, s))
            return 0;
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int minCuts = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int cuts = 1 + helper(i, k, s, dp) + helper(k + 1, j, s, dp);
            minCuts = min(minCuts, cuts);
        }
        return dp[i][j] = minCuts;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp);
    }
};

class Solution
{
    // using two memoization table
private:
    // Helper to check if s[i..j] is palindrome (uses memoization)
    bool isPalindrome(int i, int j, string &s, vector<vector<int>> &pal)
    {
        if (i >= j)
            return true;
        if (pal[i][j] != -1)
            return pal[i][j];

        if (s[i] != s[j])
            return pal[i][j] = false;
        return pal[i][j] = isPalindrome(i + 1, j - 1, s, pal);
    }

    int helper(int i, int j, string &s, vector<vector<int>> &dp, vector<vector<int>> &pal)
    {
        if (i >= j)
            return 0;
        if (isPalindrome(i, j, s, pal))
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minCuts = INT_MAX;
        for (int k = i; k < j; k++)
        {
            if (isPalindrome(i, k, s, pal))
            {
                int cuts = 1 + helper(k + 1, j, s, dp, pal);
                minCuts = min(minCuts, cuts);
            }
        }

        return dp[i][j] = minCuts;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<int>> pal(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp, pal);
    }
};

class Solution
{
    // Using tabulation
private:
    void helper(vector<vector<bool>> &t, string s, int n)
    {
        // For length = 1;
        for (int i = 0; i < n; i++)
        {
            t[i][i] = true;
        }

        for (int L = 2; L <= n; L++)
        {
            for (int i = 0; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                if (L == 2)
                {
                    t[i][j] = (s[i] == s[j]);
                }
                else
                {
                    t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
                }
            }
        }
        // palendrome table is ready
    }

public:
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        helper(t, s, n);
        vector<int> dp(n, 1e9);
        for (int i = 0; i < n; i++)
        {
            if (t[0][i] == true) // is Palendrome s[0......i]
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = INT_MAX;
                for (int k = 0; k < i; k++)
                {
                    if (t[k + 1][i] && 1 + dp[k] < dp[i]) // if right part is palendrome then only we will make the cut
                    {
                        dp[i] = 1 + dp[k];
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
