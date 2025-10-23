#include <bits/stdc++.h>
using namespace std;
class Solution
{

    // using Recursion   - TLE
private:
    int helper(int cur, int ind, vector<vector<int>> &triangle)
    {
        if (cur == triangle.size() - 1)
            return triangle[cur][ind];

        int sum1 = triangle[cur][ind] + helper(cur + 1, ind, triangle);
        int sum2 = triangle[cur][ind] + helper(cur + 1, ind + 1, triangle);
        return min(sum1, sum2);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        return helper(0, 0, triangle);
    }
};

class Solution
{

    // Using Memoization  - TLE
private:
    int helper(int cur, int ind, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        if (cur == triangle.size() - 1)
            return triangle[cur][ind];
        if (dp[cur][ind] != -1)
            return dp[cur][ind];
        int sum1 = triangle[cur][ind] + helper(cur + 1, ind, triangle, dp);
        int sum2 = triangle[cur][ind] + helper(cur + 1, ind + 1, triangle, dp);
        return dp[cur][ind] = min(sum1, sum2);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        int m = triangle.size();

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
            dp[i] = vector<int>(i + 1, -1);

        return helper(0, 0, triangle, dp);
    }
};

class Solution
{ // Using Tabulation - Accepted
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        int m = triangle.size();

        vector<vector<int>> dp(m);
        // set dp to 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i].push_back(0);
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == m - 1)
                    dp[i][j] = triangle[i][j];
                else
                {
                    dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};

class Solution
{ // optimising tabualation
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        if (triangle.size() == 1)
            return triangle[0][0];
        int m = triangle.size();

        vector<int> prev = triangle[m - 1];

        for (int i = m - 2; i >= 0; i--)
        {
            vector<int> cur(i + 1, 0);
            for (int j = 0; j <= i; j++)
            {

                cur[j] = triangle[i][j] + min(prev[j], prev[j + 1]);
            }
            prev = cur;
        }
        return prev[0];
    }
};

class Solution
{
    // Using only one vector
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        vector<int> dp = triangle[m - 1]; // start from last row

        // go upward, in-place update
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};
