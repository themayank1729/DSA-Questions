#include <bits/stdc++.h>
using namespace std;
class Solution
{ // using recursion
private:
    int helper(int ind, int buy, int cap, vector<int> &prices)
    {
        if (cap == 0 || ind == prices.size())
            return 0;
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, cap, prices), helper(ind + 1, 1, cap, prices));
        }
        else
        {
            profit = max(prices[ind] + helper(ind + 1, 1, cap - 1, prices), helper(ind + 1, 0, cap, prices));
        }
        return profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return helper(0, 1, k, prices);
    }
};

class Solution
{ // Using 2D dp  Memoization
  // intutution transaction - 0  1  2  3 . . . . . . . . . . 2*k-1
  //                          B  S  B  S
  //
  // since at max k transacitons can be done
private:
    int helper(int ind, int transaction, int tot, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size() || transaction == tot)
            return 0;
        if (dp[ind][transaction] != -1)
            return dp[ind][transaction];
        int profit = 0;
        if (transaction % 2 == 0) // means buy day
        {
            profit = max(-prices[ind] + helper(ind + 1, transaction + 1, tot, prices, dp), helper(ind + 1, transaction, tot, prices, dp));
        }
        else // means sell day
        {
            profit = max(prices[ind] + helper(ind + 1, transaction + 1, tot, prices, dp), helper(ind + 1, transaction, tot, prices, dp));
        }
        return dp[ind][transaction] = profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return helper(0, 0, 2 * k, prices, dp);
    }
};

class Solution
{
    // Using Tabulation - 0 ( (n+1) * (2*k +1)) space
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        // Base Cases
        for (int transaction = 0; transaction <= 2 * k; transaction++)
        {
            dp[n][transaction] = 0;
        }
        for (int ind = 0; ind <= n; ind++)
            dp[ind][2 * k] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int t = 0; t <= 2 * k - 1; t++)
            {
                if (t % 2 == 0)
                    dp[ind][t] = max(-prices[ind] + dp[ind + 1][t + 1], dp[ind + 1][t]);
                else
                    dp[ind][t] = max(prices[ind] + dp[ind + 1][t + 1], dp[ind + 1][t]);
            }
        }

        return dp[0][0];
    }
};
