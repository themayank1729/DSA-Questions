#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
class Solution
{
    // using recursion
private:
    int helper(int ind, int target, vector<int> &coins)
    {
        if (ind == 0)
        {
            if (target == 0)
                return 1;
            if (target % coins[ind] == 0)
                return 1;
            return 0;
        }

        int notTake = helper(ind - 1, target, coins);
        int take = 0;
        if (target >= coins[ind])
            take = helper(ind, target - coins[ind], coins);
        return take + notTake;
    }

public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();

        return helper(n - 1, amount, coins);
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
            return target % coins[ind] == 0;
        }
        if (dp[ind][target] != -1)
            return dp[ind][target];
        int notTake = helper(ind - 1, target, coins, dp);
        int take = 0;
        if (target >= coins[ind])
            take = helper(ind, target - coins[ind], coins, dp);
        return dp[ind][target] = take + notTake;
    }

public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};

class Solution
{
    // Using tabulation
public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount + 1, 0));

        for (int ind = 0; ind < n; ind++)
        {
            dp[ind][0] = 1;
        }
        for (int target = 1; target <= amount; target++)
        {
            if (target % coins[0] == 0)
                dp[0][target] = 1;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {
                ll notTake = dp[ind - 1][target];
                ll take = 0;
                if (target >= coins[ind])
                    take = dp[ind][target - coins[ind]];
                dp[ind][target] = take + notTake;
            }
        }
        return dp[n - 1][amount];
    }
};

class Solution
{
    // Using Advanced Tabulation
public:
    int change(int amount, vector<int> &coins)
    {
        if (amount < 0)
            return 0;

        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int j = coin; j <= amount; j++)
            {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
};