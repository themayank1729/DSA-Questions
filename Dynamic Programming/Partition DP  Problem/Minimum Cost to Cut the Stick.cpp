#include <bits/stdc++.h>
using namespace std;
class Solution
{ // usiing Recursion
private:
    int helper(int i, int j, vector<int> &arr)
    {
        if (i > j)
            return 0;
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = arr[j + 1] - arr[i - 1] + helper(i, ind - 1, arr) + helper(j, ind + 1, arr);
            mini = min(mini, cost);
        }
        return mini;
    }

public:
    int solve(vector<int> &nums, int n)
    {

        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.insert(arr.begin(), 0);
        arr.push_back(n);

        return helper(1, arr.size() - 2, arr);
    }
};

class Solution
{
    // using Memeoization
private:
    int helper(int i, int j, vector<int> &cuts, vector<vector<int>> &dp, int c)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = 1e9;
        for (int ind = i; ind <= j; ind++)
        {
            int cost = cuts[j + 1] - cuts[i - 1] + helper(i, ind - 1, cuts, dp, c) + helper(ind + 1, j, cuts, dp, c);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));

        return helper(1, c, cuts, dp, c);
    }
};
class Solution
{
    // using tabulation
public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

        for (int i = c; i >= 1; i--)
        {
            for (int j = 1; j <= c; j++)

            {
                if (i > j)
                    continue;
                int mini = INT_MAX;
                for (int ind = i; ind <= j; ind++)
                {

                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};