
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // using Recursion
private:
    int helper(int i, int j, bool isTrue, string &s)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            return s[i] == 'F';
        }
        int ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            int lT = helper(i, ind - 1, true, s);
            int rT = helper(ind + 1, j, true, s);
            int lF = helper(i, ind - 1, false, s);
            int rF = helper(ind + 1, j, false, s);
            if (s[ind] == '&')
            {
                if (isTrue)
                    ways += lT * rT;
                else
                    ways += (lF * rT) + (lT * rF) + (lF * rF);
            }
            else if (s[ind] == '|')
            {
                if (isTrue)
                    ways += (lT * rT) + (lF * rT) + (lT * rF);
                else
                    ways += (lF * rF);
            }
            else
            {
                if (isTrue)
                    ways += (lF * rT) + (lT * rF);
                else
                    ways += (lF * rF) + (lT * rT);
            }
        }
        return ways;
    }

public:
    int countWays(string &s)
    {
        int n = s.size();

        return helper(0, n - 1, true, s);
    }
};
class Solution
{
    // using Memoization
private:
    int helper(int i, int j, int isTrue, string &s, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
        {
            if (isTrue)
                return s[i] == 'T';
            return s[i] == 'F';
        }
        if (dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
        int ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2)
        {
            int lT = helper(i, ind - 1, 1, s, dp);
            int rT = helper(ind + 1, j, 1, s, dp);
            int lF = helper(i, ind - 1, 0, s, dp);
            int rF = helper(ind + 1, j, 0, s, dp);
            if (s[ind] == '&')
            {
                if (isTrue)
                    ways += lT * rT;
                else
                    ways += (lF * rT) + (lT * rF) + (lF * rF);
            }
            else if (s[ind] == '|')
            {
                if (isTrue)
                    ways += (lT * rT) + (lF * rT) + (lT * rF);
                else
                    ways += (lF * rF);
            }
            else
            {
                if (isTrue)
                    ways += (lF * rT) + (lT * rF);
                else
                    ways += (lF * rF) + (lT * rT);
            }
        }
        return dp[i][j][isTrue] = ways;
    }

public:
    int countWays(string &s)
    {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(0, n - 1, 1, s, dp);
    }
};

class Solution
{
    // Using Tabulation
public:
    int countWays(string &s)
    {
        int n = s.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int i = 0; i < n; i += 2)
        {

            dp[i][i][1] = s[i] == 'T';
            dp[i][i][0] = s[i] == 'F';
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= n - 1; j++)
            {

                if (i >= j)
                    continue;
                for (int isTrue = 0; isTrue <= 1; isTrue++)
                {

                    int ways = 0;
                    for (int ind = i + 1; ind <= j - 1; ind += 2)
                    {

                        int lT = dp[i][ind - 1][1]; // left true
                        int rT = dp[ind + 1][j][1]; // right True
                        int lF = dp[i][ind - 1][0]; // left false;
                        int rF = dp[ind + 1][j][0]; // right false;
                        if (s[ind] == '&')
                        {
                            if (isTrue)
                                ways += lT * rT;
                            else
                                ways += (lF * rT) + (lT * rF) + (lF * rF);
                        }
                        else if (s[ind] == '|')
                        {
                            if (isTrue)
                                ways += (lT * rT) + (lF * rT) + (lT * rF);
                            else
                                ways += (lF * rF);
                        }
                        else
                        {
                            if (isTrue)
                                ways += (lF * rT) + (lT * rF);
                            else
                                ways += (lF * rF) + (lT * rT);
                        }
                    }
                    dp[i][j][isTrue] = ways;
                }
            }
        }

        return dp[0][n - 1][1];
    }
};