#include <bits/stdc++.h>
using namespace std;
int findLowerBound(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
  int ans = -1;
    while (low <= high)
    {
        mid = (low) + (high - low) / 2;

        if (arr[mid] >=  key)
            {
            ans = mid;
             high = mid - 1;
            }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 4,7};
    int key = 6;
    cout<<"Inserting Position is  : "<<findLowerBound(arr, key)<<"\n";

    
}
