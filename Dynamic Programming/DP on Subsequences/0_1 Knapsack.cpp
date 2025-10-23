#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Using Recursion
private:
    int helper(int ind, int W, vector<int> &wt, vector<int> &val)
    {
        if (ind == 0)
        {
            if (W >= wt[0])
                return val[ind];
            else
                return 0;
        }
        int notTake = helper(ind - 1, W, wt, val);
        int take = (int)INT_MIN;

        if (W >= wt[ind])
        {
            take = val[ind] + helper(ind - 1, W - wt[ind], wt, val);
        }
        return max(take, notTake);
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        return helper(n - 1, W, wt, val);
    }
};

class Solution
{
    // Using Memoization
private:
    int helper(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (W >= wt[0])
                return val[ind];
            else
                return 0;
        }
        if (dp[ind][W] != -1)
            return dp[ind][W];
        int notTake = helper(ind - 1, W, wt, val, dp);
        int take = (int)INT_MIN;

        if (W >= wt[ind])
        {
            take = val[ind] + helper(ind - 1, W - wt[ind], wt, val, dp);
        }
        return dp[ind][W] = max(take, notTake);
    }

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return helper(n - 1, W, wt, val, dp);
    }
};

class Solution
{
    // Using Tabulation
private:
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        int maxWeight = W;
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));
        for (int w = wt[0]; w <= maxWeight; w++)
        {
            dp[0][w] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            for (int curWeight = 0; curWeight <= maxWeight; curWeight++)
            {
                int notTake = dp[ind - 1][curWeight];
                int take = INT_MIN;
                if (curWeight >= wt[ind])
                {
                    take = val[ind] + dp[ind - 1][curWeight - wt[ind]];
                }
                dp[ind][curWeight] = max(take, notTake);
            }
        }
        return dp[n - 1][maxWeight];
    }
};

class Solution
{
    // Using  Space Optimised Tabulation  by just 2 arrays
private:
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        int maxWeight = W;
        vector<int> prev(maxWeight + 1, 0);
        for (int w = wt[0]; w <= maxWeight; w++)
        {
            prev[w] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {
            vector<int> cur(maxWeight + 1, 0);
            for (int curWeight = 0; curWeight <= maxWeight; curWeight++)
            {
                int notTake = prev[curWeight];
                int take = INT_MIN;
                if (curWeight >= wt[ind])
                {
                    take = val[ind] + prev[curWeight - wt[ind]];
                }
                cur[curWeight] = max(take, notTake);
            }
            prev = cur;
        }
        return prev[maxWeight];
    }
};

class Solution
{
    // Using  Space Optimised Tabulation  by just 1 array

public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = wt.size();
        int maxWeight = W;
        vector<int> prev(maxWeight + 1, 0);
        for (int w = wt[0]; w <= maxWeight; w++)
        {
            prev[w] = val[0];
        }
        for (int ind = 1; ind < n; ind++)
        {

            for (int curWeight = maxWeight; curWeight >= 0; curWeight--)
            {
                int notTake = prev[curWeight];
                int take = INT_MIN;
                if (curWeight >= wt[ind])
                {
                    take = val[ind] + prev[curWeight - wt[ind]];
                }
                prev[curWeight] = max(take, notTake);
            }
        }
        return prev[maxWeight];
    }
};
