#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // using memoization
private:
    int helper(vector<int> &nums, int ind, vector<int> &dp)
    {
        if (ind == 0)
            return nums[ind];
        if (ind < 0)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int take = nums[ind] + helper(nums, ind - 2, dp);
        int notTake = helper(nums, ind - 1, dp);
        return dp[ind] = max(take, notTake);
    }

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        vector<int> dp(n - 1, -1);
        int ans1 = helper(temp1, n - 2, dp);
        dp.assign(dp.size(), -1);
        int ans2 = helper(temp2, n - 2, dp);
        return max(ans1, ans2);
    }
};

class Solution
{
    // using tabulation
private:
    int helper(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
        return dp[n - 1];
    }

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        };
        int ans1 = helper(temp1);

        int ans2 = helper(temp2);
        return max(ans1, ans2);
    }
};

class Solution
{
    // Optimising tabulation method
private:
    int helper(vector<int> &nums)
    {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int notTake = prev;
            int curi = max(take, notTake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

public:
    int rob(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> temp1, temp2;
        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        };
        int ans1 = helper(temp1);

        int ans2 = helper(temp2);
        return max(ans1, ans2);
    }
};