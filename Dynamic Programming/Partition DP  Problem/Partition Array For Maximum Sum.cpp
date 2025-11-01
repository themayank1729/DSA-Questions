#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Using Recursion
    int n = 0;

private:
    int helper(int i, vector<int> &arr, int k)
    {

        if (i >= n)
            return 0;
        int res = 0;
        int cur_max = -1;
        for (int j = i; j - i + 1 <= k && j < n; j++)
        {
            cur_max = max(cur_max, arr[j]);
            res = max(res, (j - i + 1) * cur_max + helper(j + 1, arr, k));
        }
        return res;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        n = arr.size();
        return helper(0, arr, k);
    }
};

class Solution
{
    // Using Memoization
    int n = 0;

private:
    int helper(int i, vector<int> &arr, int k, vector<int> &dp)
    {

        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int res = 0;
        int cur_max = -1;
        for (int j = i; j - i + 1 <= k && j < n; j++)
        {
            cur_max = max(cur_max, arr[j]);
            res = max(res, (j - i + 1) * cur_max + helper(j + 1, arr, k, dp));
        }
        return dp[i] = res;
    }

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        n = arr.size();
        vector<int> dp(n, -1);
        return helper(0, arr, k, dp);
    }
};

class Solution
{
    // Using Tabulation
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for (int size = 1; size <= n; size++) // current array size that we are considering
        {
            int cur_max = -1;
            for (int j = 1; j <= k && size - j >= 0; j++) // subarray length that we are considering for now
            {
                cur_max = max(cur_max, arr[size - j]);
                dp[size] = max(dp[size], j * cur_max + dp[size - j]);
            }
        }
        return dp[n];
    }
};