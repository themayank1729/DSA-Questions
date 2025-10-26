#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
private:
    int helper(int i, bool buy, vector<int> &prices)
    {
        if (i == prices.size())
            return 0;
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[i] + helper(i + 1, !buy, prices), 0 + helper(i + 1, buy, prices));
        }
        else
        {
            profit = max(+prices[i] + helper(i + 1, !buy, prices), 0 + helper(i + 1, buy, prices));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return helper(0, true, prices);
    }
};

class Solution
{
    // using Memoization
private:
    int helper(int i, bool buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (i == prices.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[i] + helper(i + 1, !buy, prices, dp), 0 + helper(i + 1, buy, prices, dp));
        }
        else
        {
            profit = max(+prices[i] + helper(i + 1, !buy, prices, dp), 0 + helper(i + 1, buy, prices, dp));
        }
        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, true, prices, dp);
    }
};

class Solution
{
    // using tabulation    Space -  ( (n * 2))

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int profit = 0;
        dp[n][0] = dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                }
                else
                {
                    profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

class Solution
{

    // using tabulation    Space -  ( (2 * 2))
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> prev(2, 0);
        int profit = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            vector<int> cur(2, 0);
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    profit = max(-prices[ind] + prev[0], prev[1]);
                }
                else
                {
                    profit = max(prices[ind] + prev[1], prev[0]);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }
};

class Solution
{

    // using tabulation    Space -  ( (2)) variables

public:
    int maxProfit(vector<int> &prices)
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
                    profit = max(prices[ind] + prev[1], prev[0]);
                }
                prev[buy] = profit;
            }
        }
        return prev[1];
    }
};