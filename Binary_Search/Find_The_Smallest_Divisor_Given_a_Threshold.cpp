#include <bits/stdc++.h>
using namespace std;
int calculateSum(vector<int> &arr, int mid)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + ceil((float)arr[i] / mid);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int thresh)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (calculateSum(arr, mid) <= thresh)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    cout << "answer is : " << smallestDivisor(arr, threshold);
}