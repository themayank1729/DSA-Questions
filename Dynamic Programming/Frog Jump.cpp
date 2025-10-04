#include <bits/stdc++.h>
using namespace std;
class Solution // using Recursion
{
private:
    int helper(vector<int> &height, int i)
    {
        // Base case: reached last stone
        if (i == height.size() - 1)
            return 0;

        int oneStep = INT_MAX, twoStep = INT_MAX;
        if (i + 1 < height.size())
            oneStep = abs(height[i] - height[i + 1]) + helper(height, i + 1);

        if (i + 2 < height.size())
            twoStep = abs(height[i] - height[i + 2]) + helper(height, i + 2);

        return min(oneStep, twoStep);
    }

public:
    int minCost(vector<int> &height)
    {

        return helper(height, 0);
    }
};

class Solution // using Memoization
{
private:
    int helper(vector<int> &height, int i, vector<int> &dp)
    {
        // Base case: reached last stone
        if (i == height.size() - 1)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneStep = INT_MAX, twoStep = INT_MAX;
        if (i + 1 < height.size())
            oneStep = abs(height[i] - height[i + 1]) + helper(height, i + 1, dp);

        if (i + 2 < height.size())
            twoStep = abs(height[i] - height[i + 2]) + helper(height, i + 2, dp);

        return dp[i] = min(oneStep, twoStep);
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n, -1);

        return helper(height, 0, dp);
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
