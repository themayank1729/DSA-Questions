#include <bits/stdc++.h>
using namespace std;
int findIntegerRoot(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    int low = 1;
    int high = n;
    int ans = -1;
    int mid = low + (high - low) / 2;
    while (low <= high)
    {
        if (mid * 1ll * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }

        else
            high = mid - 1;
        mid = low + (high - low) / 2;
    }
    return ans;
}
double findRealAnswer(int root, int n, int pre)
{
    double factor = 0;
    for (int i = 0; i < pre; i++)
    {
        for (double j = root; j * j <= n; j += (factor / 10))
        {
            root = j;
            factor++;
        }
    }
    return root;
}
int main()
{
    int n = 2;
    int precision = 3; // upto 3 floating places
    int root = findIntegerRoot(n);
    cout << root << "\n";
    double ans = findRealAnswer(root, n, precision);
    cout << ans << "\n";
}
