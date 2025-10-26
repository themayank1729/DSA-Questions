#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Using Recursion
    int helper(int ind, int buy, vector<int> &prices, int cap)
    {
        if (cap == 0 || ind == prices.size())
            return 0;
        int profit = 0;
        if (buy == 1)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, cap), helper(ind + 1, 1, prices, cap));
        }
        else
        {
            profit = max(prices[ind] + helper(ind + 1, 1, prices, cap - 1), helper(ind + 1, 0, prices, cap));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {

        return helper(0, 1, prices, 2);
    }
};

class Solution
{
    // using Memoization
    // using 3D dp
    int helper(int ind, int buy, vector<int> &prices, int cap, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0 || ind == prices.size())
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        int profit = 0;

        if (buy == 1)
        {
            profit = max(-prices[ind] + helper(ind + 1, 0, prices, cap, dp), helper(ind + 1, 1, prices, cap, dp));
        }
        else
        {
            profit = max(prices[ind] + helper(ind + 1, 1, prices, cap - 1, dp), helper(ind + 1, 0, prices, cap, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 1, prices, 2, dp);
    }
};

class Solution
{
    // Using Tabulation - ( n * 2 * 3)
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // First base case of   ind  == n
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap <= 2; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }
        // second base case -  cap == 0
        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }
        int profit = 0;
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 2; cap >= 0; cap--)
                {
                    if (cap == 0)
                        continue;
                    if (buy == 1)
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    else
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

class Solution
{
    // using Tabulation  -  O( 2 * 3)   * 2
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            vector<vector<int>> cur(2, vector<int>(3, 0));
            for (int buy = 0; buy <= 1; buy++)
            {

                for (int cap = 1; cap <= 2; cap++)
                {

                    if (buy == 1)
                        cur[buy][cap] = max(-prices[ind] + prev[0][cap], prev[1][cap]);
                    else
                        cur[buy][cap] = max(prices[ind] + prev[1][cap - 1], prev[0][cap]);
                }
            }
            prev = cur;
        }
        return prev[1][2];
    }
};

class Solution
{ // Using 2D dp
  // intutution transaction - 0  1  2  3
  //                          B  S  B  S
  // since at max 2 transacitons can be done
private:
    int helper(int ind, int transaction, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (ind == prices.size() || transaction == 4)
            return 0;
        if (dp[ind][transaction] != -1)
            return dp[ind][transaction];
        int profit = 0;
        if (transaction % 2 == 0) // means buy day
        {
            profit = max(-prices[ind] + helper(ind + 1, transaction + 1, prices, dp), helper(ind + 1, transaction, prices, dp));
        }
        else // means sell day
        {
            profit = max(prices[ind] + helper(ind + 1, transaction + 1, prices, dp), helper(ind + 1, transaction, prices, dp));
        }
        return dp[ind][transaction] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(0, 0, prices, dp);
    }
};

class Solution
{
    // Using Tabulation - 0 ( n * 4) space
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        // Base Cases
        for (int transaction = 0; transaction <= 3; transaction++)
        {
            dp[n][transaction] = 0;
        }
        for (int ind = 0; ind <= n; ind++)
            dp[ind][4] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int t = 0; t <= 3; t++)
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

class Solution
{
    // Using Tabulation - 0 ( n * 4) space
public:
    int maxProfit(int k,vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2*k+1, 0));
        // Base Cases
        for (int transaction = 0; transaction <= 2*k; transaction++)
        {
            dp[n][transaction] = 0;
        }
        for (int ind = 0; ind <= n; ind++)
            dp[ind][2*k] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int t = 0; t <= 2*k - 1; t++)
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

