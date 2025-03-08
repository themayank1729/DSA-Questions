#include <bits/stdc++.h>
using namespace std;
int findPeakIndex(vector<int> &arr)
{

    int low = 0;
    int high = arr.size() - 1;
    int mid = -1;
    while (low <
           high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return low;
}
int main()
{
    vector<int> arr = {5, 6, 7, 8, 4, 2};
    cout << "Peak Index Position is  : " << findPeakIndex(arr) << "\n";
}
