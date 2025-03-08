// it is also known as   : Minimum in rotated sorted array
//  Given a rotated sorted array
//find out how many times array has been rotated = 
#include <bits/stdc++.h>
using namespace std;
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
    return arr[low];
}
int main()
{
    vector<int> arr = {7, 9, 10, 11, 2, 3, 4};

    cout << "Pivot elemnt is   : " << findPivot(arr) << "\n";
}
