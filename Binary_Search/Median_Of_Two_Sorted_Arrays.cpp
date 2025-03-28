#include <bits/stdc++.h>
using namespace std;
double median_Better(vector<int> &a, vector<int> &b)
{
    // Better Approach
    // Time Complexity - O ( n1 + n2 )
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; // total size
    // required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            if (cnt == ind1)
                ind1el = a[i];
            if (cnt == ind2)
                ind2el = a[i];
            cnt++;
            i++;
        }
        else
        {
            if (cnt == ind1)
                ind1el = b[j];
            if (cnt == ind2)
                ind2el = b[j];
            cnt++;
            j++;
        }
    }

    while (i < n1)
    {
        if (cnt == ind1)
            ind1el = a[i];
        if (cnt == ind2)
            ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2)
    {
        if (cnt == ind1)
            ind1el = b[j];
        if (cnt == ind2)
            ind2el = b[j];
        cnt++;
        j++;
    }

    if (n % 2 == 1)
    {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}
double median_Optimal(vector<int> &a, vector<int> &b)
{
    // Time Complexity - O ( log (min(n1,n2)))
    int n1 = a.size();
    int n2 = b.size();
    if (n1 > n2)
        return median_Optimal(b, a);
    int low = 0, high = n1;
    int left = (n1 + n2 + 1) / 2;
    int n = n1 + n2;
    while (low <= high)
    {
        int mid1 = (high + low) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n & 1)
                return max(l1, l2);
            return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return -1;
}
int main()
{
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 3, 6, 15};
    cout << median_Better(a, b);
}