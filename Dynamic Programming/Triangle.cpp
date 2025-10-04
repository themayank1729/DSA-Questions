#include <bits/stdc++.h>
using namespace std;
class Solution
{

    //using Recursion   - TLE
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



class Solution {

    //Using Memoization  - TLE
    private:
    int helper(int cur,int ind,vector<vector<int>>&triangle,vector<vector<int>>&dp)
    {
        if(cur ==  triangle.size()-1)  return triangle[cur][ind];
             if(dp[cur][ind] != -1) return dp[cur][ind];
         int sum1 = triangle[cur][ind] + helper(cur+1,ind,triangle,dp);
         int sum2 = triangle[cur][ind] + helper(cur+1,ind+1,triangle,dp);
         return dp[cur][ind]  = min(sum1,sum2);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        int m = triangle.size();
        
        vector<vector<int>> dp(m);
for (int i = 0; i < m; i++)
    dp[i] = vector<int>(i + 1, -1);

        return helper(0,0,triangle,dp);
    }
};

class Solution {
    private:
   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];
        int m = triangle.size();
        
        vector<vector<int>> dp(m);
for (int i = 0; i < m; i++)
    dp[i] = vector<int>(i + 1, INT_MAX);
    dp[0][0] = triangle[0][0];

    for(int i =1;i<m;i++)
    {
        for(int j =0;j<=i;j++)
        {
            if(j != 0 )
            int mini = dp[i-1][j-i] + min(triangle[i][j],triangle[i][j+1]);
        
                dp[i][j]  = min(mini,dp[i][j]);
          }
    }

        return helper(0,0,triangle,dp);
    }
};