#include <bits/stdc++.h>
using namespace std;
int findPeakElement_Brute(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))
        {
            return arr[i]; // returns peak element // can be 2 or 6 but it is iterative so it will be 2
        }
    }
    return -1;
}
int findPeakElement(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    int low = 1;
    int high = n - 2;
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] > arr[mid - 1])
        {
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
    vector<int> arr = {1, 2, 1, 3, 5, 6, 4};
    cout << "First Found Peak Element is  : " << findPeakElement(arr) << "\n";
}
