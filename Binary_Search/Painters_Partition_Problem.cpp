#include <bits/stdc++.h>
using namespace std;
long sumArr(vector<int> &arr)
{
  long sum = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum += arr[i];
  }
  return sum;
}
bool isPossible(vector<int> &arr, int n, int m, int mid)
{
  int painter = 1;
  long boardSum = 0;
  for (int i = 0; i < n; i++)
  {
    if (boardSum + arr[i] <= mid)
    {
      boardSum += arr[i];
    }
    else
    {
      painter++;
      if (painter > m || arr[i] > mid)
        return false;
      boardSum = 0;
      boardSum += arr[i];
    }
  }
  return true;
}
int timeToPrintBoard(vector<int> arr, int m)
{
  int n = arr.size();
  ;
  int low = 0;
  long high = sumArr(arr);
  int mid = (low) + (high - low) / 2;
  int ans = -1;
  while (low <= high)
  {
    if (isPossible(arr, n, m, mid))
    {
      high = mid - 1;
      ans = mid;
    }
    else
      low = mid + 1;

    mid = low + (high - low) / 2;
  }
  return ans;
}
int main()
{
  vector<int> arr = {5, 5, 5, 5};
  int k = 2; // k - number of painters given
  cout << "Answer is :  " << timeToPrintBoard(arr, k) << "\n";
}
