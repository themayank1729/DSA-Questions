#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution
{
private:
    void helper(int n, int sum, const vector<int> &arr)
    {

        if (n < 0)
        {
            cout << sum << " ";
            return;
        }
        helper(n - 1, sum + arr[n], arr);
        helper(n - 1, sum, arr);
    }

public:
    void countPartitions(vector<int> &arr, int d)
    {

        helper(arr.size() - 1, 0, arr);
    }
};
int main()
{
    vector<int> v = {5, 2, 6, 4};
    int d = 3;
    Solution obj;
    obj.countPartitions(v, d);
    return 0;
}
