#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = 0;
    while (s <= e)
    {
        mid = (s) + (e - s) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int main()
{
    vector<int> arr = {-56, -1, 0, 2, 4, 5, 6, 7, 8, 9, 9, 9, 70};
    int key = 90;
    if (binarySearch(arr, key) == -1)
        cout << "element not found";
    else
        cout << binarySearch(arr, key);
}
