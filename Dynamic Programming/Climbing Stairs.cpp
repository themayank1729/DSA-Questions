#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int helper(int sum, int n, int count, vector<int> &dp)
    {
        if (sum == n)
        {
            return 1;
        }
        if (sum > n)
        {
            return 0;
        }
        if (dp[sum] != -1)
            return dp[sum];
        return dp[sum] = helper(sum + 1, n, count, dp) + helper(sum + 2, n, count, dp);
    }

public:
    int climbStairs(int n)
    {

        int count = 0;
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, -1);
        return helper(0, n, count, dp);
    }
};