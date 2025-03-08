#include <bits/stdc++.h>
using namespace std;
long sumArr(vector<int>&arr)
{
    long sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum+=arr[i];
    }
    return sum;
}
bool isPossible(vector<int>&arr,int n,int m,int mid)
{
    int studentCount = 1;
    long pageSum = 0;
    for (int i = 0; i < n; i++)
    {
          if(pageSum + arr[i] <= mid)
          {
            pageSum+=arr[i];
          }
          else
          {
            studentCount++;
            if(studentCount > m || arr[i] > mid) return false;
            pageSum = 0;
            pageSum+=arr[i];
          }
    }
    return true;
    
}
int allocatedBooks(vector<int> arr, int m)
{
    int  n =arr.size();;
    int low = 0;
    long high = sumArr(arr);
    int mid = (low) + (high - low)/2;
  int ans = -1;
    while (low <= high)
    {
        if (isPossible(arr,n,m,mid))
            {
            high = mid -1;
            ans = mid;
            }
        else
            low = mid + 1;
        
        mid = low + (high - low )/2;
    }
    return ans;
}
int main()
{
    vector<int> arr = {10,20,30,40};
      int m = 2; //m is  the number of students
    cout<<"Answer is :  "<<allocatedBooks(arr, m)<<"\n";

    
}
