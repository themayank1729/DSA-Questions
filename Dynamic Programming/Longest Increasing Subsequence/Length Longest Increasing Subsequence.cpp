#include <bits/stdc++.h>
using namespace std;
class Solution
{ // using Recursion
    int helper(int ind, int prev_ind, vector<int> &nums)
    {
        if (ind == nums.size())
            return 0;

        int take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            take = 1 + helper(ind + 1, ind, nums);

        int notTake = 0 + helper(ind + 1, prev_ind, nums);

        return max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int prev_ind = -1;

        return helper(0, prev_ind, nums);
    }
};
// In memoization we are going to store index position of last element

class Solution
{ // using Memoization
    // we have to use index shifting to represent -1 index as 0 in dp
    // since there can be runtime error in various lines where we are cehcking
    int helper(int ind, int prev_ind, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == nums.size())
            return 0;
        // No need to check for this prev_ind != -1 && in below line
        if (dp[ind][prev_ind + 1] != -1)
            return dp[ind][prev_ind + 1];

        int take = 0;
        if (prev_ind == -1 || nums[ind] > nums[prev_ind])
            take = 1 + helper(ind + 1, ind, nums, dp);

        int notTake = 0 + helper(ind + 1, prev_ind, nums, dp);

        return dp[ind][prev_ind + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int prev_ind = -1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(0, -1, nums, dp);
    }
};

class Solution
{
    // Standard Tabulation
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int prev_ind = -1;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // base for each ind == n dp[n][0...n] = 0;
        // sicne it is already zero so no worries
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                int len = 0 + dp[ind + 1][prev + 1];
                if (prev == -1 || nums[ind] > nums[prev])
                {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev + 1] = len;
            }
        }
        return dp[0][-1 + 1];
    }
};

class Solution
{
    // single array tabulation  - optimised one
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        // base for each ind == n dp[n][0...n] = 0;
        // sicne it is already zero so no worries
        int maxLen = 0;
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (nums[ind] > nums[prev])
                {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxLen = max(maxLen, dp[ind]);
        }
        return maxLen;
    }
};