#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution
{
    // Using Recursion
private:
    int helper(int ind, int length, vector<int> &price)
    {
        if (ind == 0)
        {
            return (int)(length / (ind + 1)) * price[ind];
        }

        int notTake = helper(ind - 1, length, price);
        int take = 0;
        if (length >= (ind + 1))
            take = price[ind] + helper(ind, length - (ind + 1), price);
        return max(take, notTake);
    }

public:
    int cutRod(vector<int> &price)
    {
        int length = price.size();
        return helper(length - 1, length, price);
    }
};

class Solution
{
    // using Memoization
private:
    int helper(int ind, int length, vector<int> &price, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (int)(length / (ind + 1)) * price[ind];   //ind = 0
        }
        if (dp[ind][length] != -1)
            return dp[ind][length];
        int notTake = helper(ind - 1, length, price, dp);
        int take = 0;
        if (length >= (ind + 1))
            take = price[ind] + helper(ind, length - (ind + 1), price, dp);
        return dp[ind][length] = max(take, notTake);
    }

public:
    int cutRod(vector<int> &price)
    {
        int length = price.size();
        vector<vector<int>> dp(length, vector<int>(length + 1, -1));
        return helper(length - 1, length, price, dp);
    }
};

class Solution
{
    // Using Tabualtion
public:
    int cutRod(vector<int> &price)
    {
        int length = price.size();
        vector<vector<int>> dp(length, vector<int>(length + 1, 0));

        for (int ind = 0; ind <= length; ind++)
        {
            dp[0][ind] = ind * price[0];
        }

        for (int ind = 1; ind < length; ind++)
        {
            for (int target = 0; target <= length; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = 0;
                if (target >= (ind + 1))
                    take = price[ind] + dp[ind][target - (ind + 1)];
                dp[ind][target] = max(take, notTake);
            }
        }
        return dp[length - 1][length];
    }
};