#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &ans, int row, int col, int newColor, int delRow[], int delCol[], int initialColor)
    {
        ans[row][col] = newColor;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if (nrow >= 0 && nrow < image.size() &&
                ncol >= 0 && ncol < image[0].size() &&
                image[nrow][ncol] == initialColor &&
                ans[nrow][ncol] != newColor)
            {
                dfs(image, ans, nrow, ncol, newColor, delRow, delCol, initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;

        vector<vector<int>> ans = image;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        dfs(image, ans, sr, sc, color, delRow, delCol, image[sr][sc]);

        return ans;
    }
};
