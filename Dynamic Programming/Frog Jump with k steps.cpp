#include <bits/stdc++.h>
using namespace std;
class Solution // using Recursion
{
private:
    int helper(vector<int> &height, int i, int k)
    {
        // Base case: reached last stone
        if (i == height.size() - 1)
            return 0;

        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i + j < height.size())
            {
                int dist = helper(height, i + j, k) + abs(height[i] - height[i + j]);
                minSteps = min(minSteps, dist);
            }
        }

        return minSteps;
    }

public:
    int minCost(vector<int> &height, int k)
    {

        return helper(height, 0, k);
    }
};

class Solution // using Memoization
{
private:
    int helper(vector<int> &height, int i, int k, vector<int> &dp)
    {
        // Base case: reached last stone
        if (i == height.size() - 1)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i + j < height.size())
            {
                int dist = helper(height, i + j, k, dp) + abs(height[i] - height[i + j]);
                minSteps = min(minSteps, dist);
            }
        }
        return dp[i] = minSteps;

        return minSteps;
    }

public:
    int minCost(vector<int> &height, int k)
    {
        int n = height.size();
        vector<int> dp(n, -1);

        return helper(height, 0, k, dp);
    }
};

class Solution2 // using Tabulation
{

public:
    int minCost(vector<int> &height)
    {
        // what if height.size() == 1
        int n = height.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(height[0] - height[1]);
        for (int i = 2; i < n; i++)
        {
            dp[i] = min((dp[i - 1] + abs(height[i] - height[i - 1])), (dp[i - 2] + abs(height[i] - height[i - 2])));
        }

        return dp[n - 1];
    }
};
