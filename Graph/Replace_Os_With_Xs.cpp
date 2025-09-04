#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> &mat, int delRow[], int delCol[])
  {
    visited[row][col] = 1;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < 4; i++)
    {
      int nrow = row + delRow[i];
      int ncol = col + delCol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
      {
        if (!visited[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
          dfs(nrow, ncol, visited, mat, delRow, delCol);
        }
      }
    }
  }

public:
  vector<vector<char>> fill(vector<vector<char>> &mat)
  {
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    // traversing  first and last row
    for (int j = 0; j < m; j++)
    {
      if (!visited[0][j] && mat[0][j] == 'O')
      {
        dfs(0, j, visited, mat, delRow, delCol);
      }
      if (!visited[n - 1][j] && mat[n - 1][j] == 'O')
      {
        dfs(n - 1, j, visited, mat, delRow, delCol);
      }
    }
    for (int i = 0; i < n; i++)
    {
      if (!visited[i][0] && mat[i][0] == 'O')
      {
        dfs(i, 0, visited, mat, delRow, delCol);
      }
      if (!visited[i][m - 1] && mat[i][m - 1] == 'O')
      {
        dfs(i, m - 1, visited, mat, delRow, delCol);
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (!visited[i][j] && mat[i][j] == 'O')
        {
          mat[i][j] = 'X';
        }
      }
    }

    return mat;
  }
};
