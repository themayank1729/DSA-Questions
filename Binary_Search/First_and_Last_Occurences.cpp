// ceil  - smallest number in an array >= key
// floor  - larget number in an array <= key
#include <bits/stdc++.h>
using namespace std;
int findFirstOccurence(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int posOccur = -1;
    while (low <= high)
    {
        mid = (low) + (high - low) / 2;

        if (arr[mid] == key)
        {
            posOccur = mid;
            high = mid - 1;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return posOccur;
}
int findLastOccurence(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    int posOccur = -1;
    while (low <= high)
    {
        mid = (low) + (high - low) / 2;

        if (arr[mid] == key)
        {
            posOccur = mid;
            low = mid + 1;
        }
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return posOccur;
}
int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int key = 12;
    cout << "First occurnece is  : " << findFirstOccurence(arr, key) << "\n";
    cout << "Last Occurence is : " << findLastOccurence(arr, key) << "\n";
}
