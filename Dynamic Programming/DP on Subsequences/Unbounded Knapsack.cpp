// User function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int helper(int ind, int capacity, const vector<int> &val, const vector<int> &wt)
    {
        if (ind == 0)
        {
            if (capacity >= wt[0])
                return int(capacity / wt[ind]) * val[ind];
            else
                return 0;
        }
        /* or the condition can be
          if (ind == 0)
        {
                return int(capacity / wt[ind]) * val[ind];
        }
        */

        int notTake = 0 + helper(ind - 1, capacity, val, wt);
        int take = INT_MIN;
        if (capacity >= wt[ind])
        {
            take = val[ind] + helper(ind, capacity - wt[ind], val, wt);
        }
        return max(take, notTake);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {

        int n = wt.size();
        return helper(n - 1, capacity, val, wt);
    }
};

class Solution
{

    // Using Memoization
    int helper(int ind, int capacity, const vector<int> &val, const vector<int> &wt, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return int(capacity / wt[ind]) * val[ind];
        }
        if (dp[ind][capacity] != -1)
            return dp[ind][capacity];
        int notTake = 0 + helper(ind - 1, capacity, val, wt, dp);
        int take = INT_MIN;
        if (capacity >= wt[ind])
        {
            take = val[ind] + helper(ind, capacity - wt[ind], val, wt, dp);
        }
        return dp[ind][capacity] = max(take, notTake);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {

        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return helper(n - 1, capacity, val, wt, dp);
    }
};

class Solution
{
    // Using tabulation
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {

        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int target = 0; target <= capacity; target++)
        {
            dp[0][target] = (int)(target / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= capacity; target++)
            {
                int notTake = dp[ind - 1][target];
                int take = INT_MIN;
                if (target >= wt[ind])
                    take = val[ind] + dp[ind][target - wt[ind]];
                dp[ind][target] = max(take, notTake);
            }
        }
        return dp[n - 1][capacity];
    }
};

class Solution
{
    // Using 1 Array Tabulation
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {

        int n = wt.size();
        vector<int> prev(capacity + 1, 0);

        for (int target = 0; target <= capacity; target++)
        {
            prev[target] = (int)(target / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= capacity; target++)
            {
                int notTake = prev[target];
                int take = INT_MIN;
                if (target >= wt[ind])
                    take = val[ind] + prev[target - wt[ind]];
                prev[target] = max(take, notTake);
            }
        }
        return prev[capacity];
    }
};