#include <bits/stdc++.h>
using namespace std;
class Solution
{ // using Resursion
    int helper(int ind, int buy, vector<int> &prices)
    {
        if (ind >= prices.size())
            return 0;

        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices), helper(ind + 1, 1, prices));
        }
        else
        {
            profit = max(prices[ind] + helper(ind + 2, 1, prices), helper(ind + 1, 0, prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return helper(0, 1, prices);
    }
};

class Solution
{
    // using Memoization
    int helper(int ind, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, dp), helper(ind + 1, 1, prices, dp));
        }
        else
        {
            profit = max(prices[ind] + helper(ind + 2, 1, prices, dp), helper(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
    }
};

class Solution
{
    // using tabulation
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Base case
        dp[n][0] = dp[n][1] = dp[n + 1][0] = dp[n + 1][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};