#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // using Tabulation and hashing for tracing back the element
public:
    vector<int> getLIS(vector<int> &arr)
    {

        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int i = 0; i < n; i++) // initializing hash with its own values or you can do that in  below
        {
            hash[i] = i;
        }
        int lastIndex = 0; // position of element that is getting highest dp[i] --> last element in LIS
        int maxLIS = 0;    // in form od dp[i]
        for (int ind = 0; ind < n; ind++)
        {
            hash[ind] = ind; // this  will also work
            for (int prev = 0; prev < ind; prev++)
            {
                // second condition checks that we only update the dp[ind] when it gets higher value that is we wont update the value of dp[ind] if it gets further same value from different prev
                if (arr[ind] > arr[prev] && dp[prev] + 1 > dp[ind])
                {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                }
            }
            if (dp[ind] > maxLIS)
            {
                maxLIS = dp[ind];
                lastIndex = ind;
            }
        }
        // now every element in LIS is hashed
        vector<int> ans;

        ans.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];

            ans.push_back(arr[lastIndex]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
