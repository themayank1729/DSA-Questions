#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
private:
    int helper(int ind, int target, vector<int> &arr)
    {
        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0)
                return 1;
            if (target == arr[0])
                return 1;
            return 0;
        }

        int notTake = helper(ind - 1, target, arr);
        int take = 0;
        if (target >= arr[ind])
            take = helper(ind - 1, target - arr[ind], arr);
        return take + notTake;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (target > totalSum || (target + totalSum) % 2 != 0)
            return 0;

        int sum = (totalSum + target) / 2;
        return helper(n - 1, sum, nums);
    }
};

class Solution
{
    // Using Memoization
private:
    int helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = helper(ind - 1, target, arr, dp);
        int take = 0;
        if (target >= arr[ind])
            take = helper(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take + notTake;
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;

        int sum = (totalSum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        return helper(n - 1, sum, nums, dp);
    }
};

class Solution
{
    // Using Tabulation

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (target + totalSum) % 2 != 0)
            return 0;
        int sum = (totalSum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if (nums[0] == 0)
            dp[0][0] = 2;
        else if (nums[0] <= sum) // if We do not do it then it can access undeclared memory of dp array
            dp[0][nums[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int tar = 0; tar <= sum; tar++)
            {
                int notTake = dp[ind - 1][tar];
                int take = 0;
                if (tar >= nums[ind])
                {
                    take = dp[ind - 1][tar - nums[ind]];
                }
                dp[ind][tar] = take + notTake;
            }
        }
        return dp[n - 1][sum];
    }
};