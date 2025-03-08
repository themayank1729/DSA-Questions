#include <bits/stdc++.h>
using namespace std;
// Time Complexity  - O( log (sum(arr) - max(arr) )  * (n))
int requiredDays(vector<int> &arr, int capacity, int givenDdays)
{
    int n = arr.size();
    int load = 0;
    int reqDays = 1;

    for (int j = 0; j < n; j++)
    {
        if (reqDays > givenDdays)
            return INT_MAX;
        if (load + arr[j] <= capacity)
        {
            load = load + arr[j];
        }
        else
        {
            reqDays++;
            load = arr[j];
        }
    }
    return reqDays;
}
// for Brute force approach just iterate linearly from 1 to max_element(arr);
int numberOfDays(vector<int> arr, int days)
{
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (requiredDays(arr, mid, days) <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans; // or return low;
}
int main()
{
    // we have to make 'm' bouquets of 'k' flowers
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5; // this is number of days that it  can atmost take to ship  packages so we want least capacity of ship
    // given  1 ship can take "m" weights per day

    cout << "Answer is :  " << numberOfDays(weights, days) << "\n";
}
// note : just think about this -       max(arr)   <=  ans  <=  sum(arr)
