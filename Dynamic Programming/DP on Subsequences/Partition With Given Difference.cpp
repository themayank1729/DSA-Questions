#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // using Recursion  & Memoization
private:
    int helper(const vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (arr[0] == 0 && target == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = helper(arr, ind - 1, target, dp);
        int take = 0;
        if (target >= arr[ind])
            take = helper(arr, ind - 1, target - arr[ind], dp);

        return dp[ind][target] = take + notTake;
    }
    int findWays(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return helper(arr, n - 1, target, dp);
    }

public:
    int countPartitions(vector<int> &arr, int d)
    {
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        if (totSum - d < 0 || (totSum - d) % 2 != 0)
            return 0;

        return findWays(arr, (totSum - d) / 2);
    }
};

class Solution
{ // Using Tabulation
private:
    int helper(const vector<int> &arr, int target, vector<vector<int>> &dp)
    {
        int n = arr.size();

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        if (arr[0] <= target)
        {
            if (arr[0] == 0)
                dp[0][0] = 2;
            else
                dp[0][arr[0]] = 1;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int sum = 0; sum <= target; sum++)
            {
                int notTake = dp[ind - 1][sum];
                int take = 0;
                if (sum >= arr[ind])
                    take = dp[ind - 1][sum - arr[ind]];
                dp[ind][sum] = take + notTake;
            }
        }
        return dp[n - 1][target];
    }
    int findWays(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        return helper(arr, target, dp);
    }

public:
    int countPartitions(vector<int> &arr, int d)
    {
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        if (totSum - d < 0 || (totSum - d) % 2 != 0)
            return 0;

        return findWays(arr, (totSum - d) / 2);
    }
};