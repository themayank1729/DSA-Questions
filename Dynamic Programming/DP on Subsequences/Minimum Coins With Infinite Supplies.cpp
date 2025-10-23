#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
private:
    int helper(int ind, int target, vector<int> &coins)
    {
        if (ind == 0)
        {
            return target % coins[0] == 0 ? target / coins[0] : (int)(1e9);
        }
        int notTake = helper(ind - 1, target, coins);
        int take = (int)(1e9);
        if (target >= coins[ind])
        {
            take = 1 + helper(ind, target - coins[ind], coins);
        }
        return min(take, notTake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        int ans = helper(n - 1, amount, coins);
        return ans == 1e9 ? -1 : ans;
    }
};

class Solution
{
    // Using Memoization
private:
    int helper(int ind, int target, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return target % coins[0] == 0 ? target / coins[0] : (int)(1e9);
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = helper(ind - 1, target, coins, dp);
        int take = (int)(1e9);
        if (target >= coins[ind])
        {
            take = 1 + helper(ind, target - coins[ind], coins, dp);
        }
        return dp[ind][target] = min(take, notTake);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(n - 1, amount, coins, dp);
        return ans == 1e9 ? -1 : ans;
    }
};

class Solution
{
    // Using Tabulation

public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = 1e9;

                if (target >= coins[ind])
                {

                    take = 1 + dp[ind][target - coins[ind]];
                }
                dp[ind][target] = min(take, notTake);
            }
        }

        return dp[n - 1][amount] == 1e9 ? -1 : dp[n - 1][amount];
    }
};

class Solution
{
    // Space Optimisation by 2 arrays
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<int> prev(amount + 1, 1e9);
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> cur(amount + 1, INT_MAX);
            for (int target = 0; target <= amount; target++)
            {
                int notTake = prev[target];
                int take = 1e9;

                if (target >= coins[ind])
                {

                    take = 1 + cur[target - coins[ind]];
                }
                cur[target] = min(take, notTake);
            }
            prev = cur;
        }

        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};

class Solution
{
    // Space Optimisation by 1 array
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<int> prev(amount + 1, 1e9);
        for (int target = 0; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
        }

        for (int ind = 1; ind < n; ind++)
        {

            for (int target = 0; target <= amount; target++)
            {
                int notTake = prev[target];
                int take = 1e9;

                if (target >= coins[ind])
                {

                    take = 1 + prev[target - coins[ind]];
                }
                prev[target] = min(take, notTake);
            }
        }

        return prev[amount] == 1e9 ? -1 : prev[amount];
    }
};