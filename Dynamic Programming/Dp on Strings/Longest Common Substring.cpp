#include <bits/stdc++.h>
using namespace std;
class Solution
{
    //Brute force
public:
    int longestCommonSubstr(string &s1, string &s2)
    {

        int n = s1.size();
        int m = s2.size();
        int len = 0, maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int i1 = i, i2 = j;
                while (s1[i1] == s2[i2] && i1 < n && i2 < m)
                {
                    len++;
                    i1++;
                    i2++;
                }

                maxLen = max(maxLen, len);
                len = 0;
            }
        }
        return maxLen;
    }
};


class Solution {
   //Using Tabulation
 public:
    int longestCommonSubstr(string& s1, string& s2) {
    int n = s1.size();
    int m  = s2.size();
  int maxLen = 0;
vector<vector<int>>dp(n+1,vector<int>(m+1,0));

for(int i = 1 ;i <=n ;i++)
{
    for(int j = 1;j <= m;j++)
    {
        if(s1[i-1] == s2[j-1])
        {
            dp[i][j] = 1 + dp[i-1][j-1];
        }
        else
        {
            dp[i][j]= 0;
        }
        
        maxLen = max(maxLen,dp[i][j]);
    }
}
return maxLen;
        
        
        
    }
};