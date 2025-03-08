#include <bits/stdc++.h>
using namespace std;
int helper(int num, int k)
{

    if (k == 0)
        return 1;
    int res = helper(num, k / 2);
    if (k & 1)
    {
        return res * res * (num);
    }
    else
    {
        return res * res;
    }
}
int findNthRoot(int num, int n)
{
    int low = 1;
    int high = num;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int calculatedPow = helper(mid, n);
        if (calculatedPow == num)
            return mid;
        else if (calculatedPow < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    int num = 65;
    int n = 3;
    cout << "Nth root is : " << findNthRoot(num, n);
}