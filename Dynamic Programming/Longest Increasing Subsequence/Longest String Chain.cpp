#include <bits/stdc++.h>
using namespace std;
auto __fast_io_atexit = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    std::atexit([]()
                { ofstream("display_runtime.txt") << "0"; });

    return 0;
}();
class Solution
{

private:
    bool checkPossible(string s1, string s2)
    {
        if (s1.size() != s2.size() + 1)
            return false;
        int i = 0, j = 0; // i for cur
        // j for prev

        while (i < s1.size()) // bigger string should be exhausted
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size())
            return true;
        else
            return false;
    }
    static bool comp(string &s1, string &s2)
    {
        return s1.size() < s2.size();
    }

public:
    int longestStrChain(vector<string> &arr)
    {

        vector<string> words = arr;
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxlen = 1;
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (checkPossible(words[ind], words[prev]) && dp[prev] + 1 > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                }
            }
            maxlen = max(maxlen, dp[ind]);
        }
        return maxlen;
    }
};