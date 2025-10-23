#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Memoization
private:
    bool helper(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return dp[ind][target] = 1;

        if (ind == 0)
            return dp[ind][target] = (arr[0] == target ? 1 : 0);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTaken = helper(ind - 1, target, arr, dp);
        bool taken = false;
        if (arr[ind] <= target)
            taken = helper(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken || taken;
    }

public:
    int minDifference(vector<int> &arr)
    {
        int n = arr.size();
        int totSum = accumulate(arr.begin(), arr.end(), 0);

        vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));

        for (int i = 0; i <= totSum; i++)
        {
            helper(n - 1, i, arr, dp);
        }

        int mini = INT_MAX;
        for (int i = 0; i <= totSum; i++)
        {
            if (dp[n - 1][i] == 1)
            {
                int diff = abs(i - (totSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};

class Solution
{
    // Using tabulation
private:
    void helper(vector<int> &arr, int sum, vector<vector<bool>> &dp)
    {
        int n = arr.size();
        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][0] = true;
        }
        dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= sum; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (target >= arr[ind])
                {
                    take = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = take | notTake;
            }
        }
    }

public:
    int minDifference(vector<int> &arr)
    {
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        helper(arr, sum, dp);
        int minDiff = 1e8;
        for (int target = 0; target <= sum; target++)
        {
            if (dp[n - 1][target])
            {
                int s2 = sum - target;
                minDiff = min(minDiff, abs(s2 - target));
            }
        }
        return minDiff;
    }
};