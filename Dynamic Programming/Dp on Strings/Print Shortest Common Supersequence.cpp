#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void helper(string &s1, string &s2, vector<vector<int>> &dp)
    {
        int n = s1.size();
        int m = s2.size();
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
    }

public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        helper(str1, str2, dp);

        int i = n;
        int j = m;
        int length = n + m - dp[n][m];
        string ans(length, '@'); // dummy character becasue we know the length of supersequence
        int index = length - 1;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans[index--] = str1[i - 1];
                cout << str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans[index--] = str1[i - 1];

                i--;
            }
            else
            {
                ans[index--] = str2[j - 1];

                j--;
            }
        }
        while (i > 0)
        {
            ans[index--] = str1[i - 1];
            i--;
        }
        while (j > 0)
        {
            ans[index--] = str2[j - 1];
            j--;
        }
        return ans;
    }
};