#include <bits/stdc++.h>
using namespace std;
int findUnique(vector<int> &arr, int n)
{
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 2] != arr[n - 1])
        return arr[n - 1];
    int low = 1;
    int high = n - 2;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];
        // for left half (since this position can be even or odd)
        else if ((mid & 1 && arr[mid - 1] == arr[mid]) || (!(mid & 1) && arr[mid + 1] == arr[mid]))
        {
            // eliminating left half
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {0, 1, 1, 2, 2, 5, 5, 6, 6};
    int n = arr.size();
    cout << findUnique(arr, n);
}
