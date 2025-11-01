#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // if only one condition is allowed -- >  increase then decrease
    /*
    n LBS there should be both increasing and decreasing part . so while calculating the maxi  , make sure that the both the dp1 and dp2 at the specific index is greater than 1 as the index we are calculating should have at least 2 which means the there is some increasing / decreasing part after that element is existing
    */
    void helper(vector<int> &arr, vector<int> &dp_1, vector<int> &dp_2)
    {
        int n = arr.size();
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[ind] > arr[prev] && dp_1[prev] + 1 > dp_1[ind])
                {
                    dp_1[ind] = 1 + dp_1[prev];
                }
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = n - 1; prev > ind; prev--)
            {
                if (arr[ind] > arr[prev] && dp_2[prev] + 1 > dp_2[ind])
                {
                    dp_2[ind] = 1 + dp_2[prev];
                }
            }
        }
    }

public:
    int LongestBitonicSequence(int n, vector<int> &arr)
    {

        vector<int> dp_1(n, 1);
        vector<int> dp_2(n, 1);
        helper(arr, dp_1, dp_2);

        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp_1[i] > 1 && dp_2[i] > 1)
                maxlen = max(maxlen, dp_1[i] + dp_2[i] - 1);
        }
        return maxlen;
    }
};

class Solution
{
    // if all three conditions are allowed -- > Strictly increasing, decreasing, increase then decrease

    void helper(vector<int> &arr, vector<int> &dp_1, vector<int> &dp_2)
    {
        int n = arr.size();
        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev < ind; prev++)
            {
                if (arr[ind] > arr[prev] && dp_1[prev] + 1 > dp_1[ind])
                {
                    dp_1[ind] = 1 + dp_1[prev];
                }
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = n - 1; prev > ind; prev--)
            {
                if (arr[ind] > arr[prev] && dp_2[prev] + 1 > dp_2[ind])
                {
                    dp_2[ind] = 1 + dp_2[prev];
                }
            }
        }
    }

public:
    int LongestBitonicSequence(int n, vector<int> &arr)
    {

        vector<int> dp_1(n, 1);
        vector<int> dp_2(n, 1);
        helper(arr, dp_1, dp_2);

        int maxlen = 0;

        for (int i = 0; i < n; i++)
        {
            maxlen = max(maxlen, dp_1[i] + dp_2[i] - 1);
        }
        return maxlen;
    }
};
