#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int helper(int ind, int buy, int &fee, vector<int> &prices)
    {
        if (ind == prices.size())
            return 0;

        int profit = 0;
        if (buy)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, fee, prices), helper(ind + 1, 1, fee, prices)); // either -prices[ind] - fee
        }
        else
        {
            profit = max(prices[ind] - fee + helper(ind + 1, 1, fee, prices), helper(ind + 1, 0, fee, prices)); // or this
        }
        return profit; // it wont work profit - fee
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return helper(0, 1, fee, prices);
    }
};

class Solution
{
    // using Memoization
private:
    int helper(int i, int buy, int fee, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[i] + helper(i + 1, 0, fee, prices, dp), 0 + helper(i + 1, 1, fee, prices, dp));
        }
        else
        {
            profit = max(+prices[i] - fee + helper(i + 1, 1, fee, prices, dp), 0 + helper(i + 1, buy, fee, prices, dp));
        }
        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, fee, prices, dp);
    }
};

class Solution
{

    // using tabulation    Space -  ( (2)) variables

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> prev(2, 0);
        int profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {

            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    profit = max(-prices[ind] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[ind] - fee + prev[1], prev[0]);
                }
                prev[buy] = profit;
            }
        }
        return prev[1];
    }
};