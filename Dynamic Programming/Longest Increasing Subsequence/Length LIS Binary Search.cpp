#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // My logic
    void replaceElement(int x, vector<int> &sub)
    {
        int s = 0;
        int e = sub.size() - 1;

        int pos = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (sub[mid] == x)
            {
                // we are returning back without doing anything if the x is already present in the "sub" array (special case when elemnt gets repeated)
                return;
            }
            else if (sub[mid] > x)
            {
                pos = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        if (pos != -1)
            sub[pos] = x;
        else
            sub.push_back(x);
    }
    int helper(vector<int> &arr)
    {

        vector<int> sub;
        int n = arr.size();
        for (int ind = 0; ind < n; ind++)
        {
            if (sub.empty() || sub.back() < arr[ind])
            {
                sub.push_back(arr[ind]);
            }
            else
            {
                replaceElement(arr[ind], sub);
            }
        }
        return sub.size();
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {

        return helper(nums);
    }
};

class Solution
{
    // using lower bound    int helper(vector<int> &arr)

    // we are using lower bound so that if we can find the element that is equal to x then just replace with that element
    int helper(vector<int> &arr)
    {
        vector<int> temp;

        int n = arr.size();
        for (int ind = 0; ind < n; ind++)
        {
            if (temp.empty() || temp.back() < arr[ind])
            {
                temp.push_back(arr[ind]);
            }
            else
            {
                auto it = lower_bound(temp.begin(), temp.end(), arr[ind]); // returns iterator
                // it returns end when element is not found
                int index = it - temp.begin(); // if it  = temp.end() that is LB NOT FOUND then
                // temp.end() - temp.begin() == temp.size()
                if (index == temp.size())
                    temp.push_back(arr[ind]);
                else
                    temp[index] = arr[ind];
            }
        }
        return temp.size();
    }

public:
    int
    lengthOfLIS(vector<int> &nums)
    {

        return helper(nums);
    }
};

class Solution
{
    // Improved

public:
    int lengthOfLIS(vector<int> &arr)
    {

        int n = arr.size();

        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > temp.back())
            {
                temp.push_back(arr[i]);
                len++;
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[index] = arr[i];
            }
        }
        return len;
    }
};