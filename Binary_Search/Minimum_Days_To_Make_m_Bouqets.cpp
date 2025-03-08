#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int days, int m, int k)
{
    int n = arr.size();
    int count = 0;
    int bouqets = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] <= days)
        {
            count++;
        }
        else
        {
            bouqets += (count / k);
            count = 0;
        }
    }
    bouqets += (count / k);
    return bouqets >= m;
}
//for Brute force approach just iterate linearly from 1 to max_element(arr);
int numberOfDays(vector<int> arr, int m, int k)
{
    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, mid, m, k))
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
    vector<int> arr = {5, 5, 5, 5, 10, 5, 5};

    int m = 2; // m is  the number of bouquets
    int k = 3; // k is the number of adjacent flowers that should be n each bouquets
    cout << "Answer is :  " << numberOfDays(arr, m, k) << "\n";
}
