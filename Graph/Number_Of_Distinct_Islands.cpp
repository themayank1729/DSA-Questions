#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
    private:
    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&vec,int row0,int col0)
    {
           int n =grid.size();
        int m = grid[0].size();
        visited[r][c] = 1;
        vec.push_back({r-row0,c-col0});
          int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
      for (int i = 0; i < 4; i++)
    {
      int nrow = r + delRow[i];
      int ncol = c + delCol[i];
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
      {
        if (!visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
          dfs(nrow, ncol, grid,visited, vec,row0,col0);
        }
      }
    }

        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int  j = 0; j < m; j++)
            {
                if(!visited[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,visited,vec,i,j);
                    st.insert(vec);
                }
            }
            
        }
        return st.size();
        
    }
};
