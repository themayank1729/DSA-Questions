#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
private:
    bool helper(int ind, int sum, vector<int> &arr)
    {
        if (sum == 0)
            return true;
        if (ind == 0)
            return arr[ind] == sum;
        bool notTake = helper(ind - 1, sum, arr);
        bool take = false;
        if (sum >= arr[ind])
            take = helper(ind - 1, sum - arr[ind], arr);
        return take || notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {

        return helper(arr.size() - 1, sum, arr);
    }
};

class Solution
{
    // Using Memoization
private:
    bool helper(int ind, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return true;
        if (ind == 0)
            return arr[ind] == sum;
        if (dp[ind][sum] != -1)
            return dp[ind][sum] == 1;
        bool notTake = helper(ind - 1, sum, arr, dp);
        bool take = false;
        if (sum >= arr[ind])
            take = helper(ind - 1, sum - arr[ind], arr, dp);
        return dp[ind][sum] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return helper(arr.size() - 1, sum, arr, dp);
    }
};

class Solution
{
    // Using  Tabulation  -  mayank
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, (vector<bool>(sum + 1, false)));
        for (int ind = 0; ind <= n; ind++)
        {
            dp[ind][0] = true;
        }
        dp[0][arr[0]] = true; // dp[0][4]  if there is array of elemnts in which arr[0]  = 4 then it can make the score of 4 so dp[0][4] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= sum; target++)
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
        return dp[n - 1][sum];
    }
};

class Solution
{
    // Using space optimsed Tabulation  -  Strivers
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        prev[0] = prev[arr[0]] = true;
        for (int ind = 1; ind < n; ind++)
        {
            vector<bool> cur(sum + 1, 0);
            cur[0] = true;
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = prev[target];
                bool take = false;
                if (target >= arr[ind])
                {
                    take = prev[target - arr[ind]];
                }
                cur[target] = take | notTake;
            }
            prev = cur;
        }

        return prev[sum];
    }
};
