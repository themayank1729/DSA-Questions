#include <bits/stdc++.h>
using namespace std;

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
