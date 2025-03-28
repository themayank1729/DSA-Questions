#include <bits/stdc++.h>
using namespace std;
//Peak elemnt - which is greater than all four counter parts elemnts in all four directions 
//Brute force Time Complexity - O ( n * m * 4)
//which can be optimized to O (n * m)   
// Hint -  just give the Maximum element in the matrix prsent
int findMaxIndex(vector<vector<int>>&mat,int n,int m,int col)
{
  int maxVal = -1,index = -1;
  for (size_t i = 0; i < n; i++)
  {
     if(mat[i][col] > mat[i][col]);
     index = i;
  }
  return index;
  
}
vector<int> peakElement(vector<vector<int>> &mat)
{
   int n = mat.size();  // Row
   int m = mat[0].size(); // Column
   int low = 0,high = m - 1;  // Column 0 and last Column

   while(low <= high)
   {
    int mid = low + (high - low)/2;
    int maxRowIndex = findMaxIndex(mat,n,m,mid);
   int  left = mid-1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
   int right = mid+ 1 < m ? mat[maxRowIndex][mid+1] : -1;

   if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
   {
    return {maxRowIndex,mid};
   }  
   else if(mat[maxRowIndex][mid] < left)
   {
    high = mid -1;
   }
   else
   {
    low  = mid  + 1;
   }
   }
   return {-1,-1};
}
int main()
{

    vector<vector<int>> mat = {{4, 2, 5, 1, 4, 5}, {2, 9, 3, 2, 3, 2}, {1, 7, 6, 0, 1, 3}, {3, 6, 2, 3, 7, 2}};
vector<int>ans = peakElement(mat);
cout<<ans[0] <<"  "<<ans[1];
}