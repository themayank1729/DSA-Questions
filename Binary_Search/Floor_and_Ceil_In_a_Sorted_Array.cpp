// ceil  - smallest number in an array >= key
// floor  - larget number in an array <= key
#include <bits/stdc++.h>
using namespace std;
int findFloor(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int ans = -1;
    while (low <= high)
    {
        mid = (low) + (high - low) / 2;

        if (arr[mid] <= key)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int findCeil(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int ans = -1;
    while (low <= high)
    {
        mid = (low) + (high - low) / 2;

        if (arr[mid] >= key)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4, 7, 8, 9, 9, 9, 11};
    int key = 3;
    cout << "LOWER BOUND IS : " << findFloor(arr, key) << "\n";
    cout << "LOWER BOUND IS : " << findCeil(arr, key) << "\n";
}
