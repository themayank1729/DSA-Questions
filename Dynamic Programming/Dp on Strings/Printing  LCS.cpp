#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void helper(const string &s1, const string &s2, vector<vector<int>> &dp)
    {
        int n = s1.size();
        int m = s2.size();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

public:
    string printLCS(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        helper(s1, s2, dp);
        int i = n, j = m;
        int length = dp[n][m];
        string ans(length, '@');
        int index = length - 1;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[index--] = s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                i--;
            }
            else if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
        }

        return ans;
    }
};
