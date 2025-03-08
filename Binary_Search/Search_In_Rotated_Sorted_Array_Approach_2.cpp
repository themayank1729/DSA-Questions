#include <bits/stdc++.h>
using namespace std;
int searchElement(vector<int> &arr, int n, int target)
{
    int low = 0;
    int high = n - 1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (arr[mid] == target)
            return mid;
        else if (arr[low] <= arr[mid])
        {
            // if left half will bw sorted
            if (arr[low] <= target && target <= arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            // if right half will bw sorted
            if (arr[mid] <= target && target <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }

        mid = low + (high - low) / 2;
    }
    return -1;
}
int main()
{
    vector<int> arr = {7, 9, 10, 11, 2, 3, 4};
    int n = arr.size();
    int key = 1;
    cout << "Key elemnt is present at  : " << searchElement(arr, n, key) << "\n";
}
