#include <bits/stdc++.h>
using namespace std;
// just return the Row and Column number of target element
vector<int> searchIn2D(vector<vector<int>> &mat, int target)
{
    // Time Complexity =  O ( m + n )
    int n = mat.size();
    int m = mat[0].size();
    int row = 0, column = m - 1;
    while (row < n && column >= 0)
    {
        if (mat[row][column] == target)
        {
            return {row, column};
        }
        else if (mat[row][column] > target)
        {
            column--;
        }
        else
        {
            row++;
        }
    }
    return {-1, -1};
}
int main()
{
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 14;
    // 0 based indexing
    vector<int> ans = searchIn2D(mat, target);
    cout << ans[0] << " " << ans[1];
}