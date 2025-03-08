#include <bits/stdc++.h>
using namespace std;
int requiredTime(vector<int> &bananas, int bananasPerHour, int maxHours)
{
    int totalHrs = 0;
    ;
    for (int i = 0; i < bananas.size(); i++)
    {
        if (totalHrs > maxHours)
            return INT_MAX;
        totalHrs += ceil((float)bananas[i] / bananasPerHour);
    }
    return totalHrs;
}
int minimumBananas(vector<int> bananas, int maxHours)
{
    int low = 1;
    int high = *max_element(bananas.begin(), bananas.end());
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (requiredTime(bananas, mid, maxHours) <= maxHours)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> bananas = {3, 6, 7, 11}; // pile of bananas
    int maxHours = 8;                    // koko can take to eat bananas
    cout << "koko has to eat " << minimumBananas(bananas, maxHours) << " bananas per hour ";
}