#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion by Strivers Approach
private:
    int helper(vector<int> &arr, int ind)
    {
        if (ind == arr.size() - 1)
            return arr[ind];
        if (ind >= arr.size())
            return 0;

        int pick = arr[ind] + helper(arr, ind - 2);
        int notPick = helper(arr, ind - 1);
        return max(pick, notPick);
    }

public:
    int findMaxSum(vector<int> &arr)
    {
        int i = arr.size();
        vector<int> dp(i, -1);
        return helper(arr, i - 1);
    }
};
class Solution
{
    // Using Memoization
private:
    int helper(vector<int> &arr, int ind, vector<int> &dp)
    {
        if (ind == arr.size() - 1)
            return arr[ind];
        if (ind >= arr.size())
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int pick = arr[ind] + helper(arr, ind + 2, dp);
        int notPick = helper(arr, ind + 1, dp);
        return dp[ind] = max(pick, notPick);
    }

public:
    int findMaxSum(vector<int> &arr)
    {
        int i = arr.size();
        vector<int> dp(i, -1);
        return helper(arr, 0, dp);
    }
};

class Solution
{
    // Using Tabulation

public:
    int findMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 0);

        dp[0] = arr[0];

        for (int i = 1; i < n; i++)
        {

            int take = arr[i];
            if (i > 1)
                take += dp[i - 2];
            int notTake = dp[i - 1];
            dp[i] = max(take, notTake);
        }
      
        return dp[n-1];
    }
};