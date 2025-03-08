#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &arr, int low, int high, int key)
{
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
        mid = low + (high - low) / 2;
    }
    return -1;
}
int findPivot(vector<int> &arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = low + (high - low) / 2;

    while (low < high)
    {

        if (arr[mid] > arr[0])
        {

            low = mid + 1;
        }
        else
        {
            high = mid;
        }
        mid = (low) + (high - low) / 2;
    }
    return low;
}
int main()
{
    vector<int> arr = {7, 9, 10, 11, 2, 3, 4};
    int n = arr.size();
    int foundAt = -1;
    int key = 1;
    int pivot = findPivot(arr);
    cout << pivot << '\n';
    cout << arr[pivot] << "\n";
    if (key >= arr[pivot] && key <= arr[n - 1])
    {
        foundAt = binarySearch(arr, pivot, n - 1, key);
        cout << foundAt << "\n";
    }
    else
    {
        foundAt = binarySearch(arr, 0, pivot - 1, key);
        cout << foundAt << '\n';
    }

    cout << "Key elemnt is present at  : " << foundAt << "\n";
}
