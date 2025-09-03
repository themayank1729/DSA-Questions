#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));  //strores the distance of nearest 1 from every particualar cell
        queue<pair<pair<int,int>,int>>q;  // row,col,step distance

         
         for (int i = 0; i < n; i++)
         {
           for (int j = 0; j < m; j++)
           {
               if(grid[i][j] == 1)
               {
                q.push({{i,j},0});
                visited[i][j] = 1;
               }
           }
         }
         


         int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
                 q.pop();
            dist[r][c] = steps;
        
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m)
                {
                  if(visited[nrow][ncol] == 0 && grid[nrow][ncol] == 0)
                  {
                    q.push({{nrow,ncol},steps+1});
                    visited[nrow][ncol] = 1;
                  }
                }
                
            }
            
        }
        return dist;
        
    }
};