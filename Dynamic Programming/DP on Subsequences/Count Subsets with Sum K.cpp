#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
private:
    int helper(vector<int> &arr, int ind, int target)
    {
        if (index == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }
        int notTake = helper(arr, ind - 1, target);
        int take = 0;
        if (arr[ind] <= target)
            take = helper(arr, ind - 1, target - arr[ind]);
        return take + notTake;
    }

public:
    int perfectSum(vector<int> &arr, int target)
    {

        return helper(arr, arr.size() - 1, target);
    }
};
class Solution
{
    // Using Memoization
private:
    int helper(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
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
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = helper(arr, ind - 1, target, dp);
        int take = 0;
        if (arr[ind] <= target)
            take = helper(arr, ind - 1, target - arr[ind], dp);
        return dp[ind][target] = take + notTake;
    }

public:
    int perfectSum(vector<int> &arr, int target)
    {
        vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

        return helper(arr, arr.size() - 1, target, dp);
    }
};

class Solution
{
    // using tabulation
public:
    int perfectSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;

        if (arr[0] <= sum)
        {
            if (arr[0] == 0)
                dp[0][0] = 2;
            else
                dp[0][arr[0]] = 1;
        }

        for (int i = 1; i < n; i++)
        {
            for (int target = 0; target <= sum; target++)
            {
                int notTake = dp[i - 1][target];
                int take = 0;
                if (target >= arr[i])
                    take = dp[i - 1][target - arr[i]];

                dp[i][target] = take + notTake;
            }
        }

        return dp[n - 1][sum];
    }
};


