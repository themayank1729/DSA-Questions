// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // 1 based indexing
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return; // no need to attach
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // rank are same
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return; // no need to attach
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] = size[ulp_u] + size[ulp_v];
        }
        else if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] = size[ulp_u] + size[ulp_v];
        }
    }
    int getComponentSize(int node)
    {
        int ulp = findUParent(node);
        return size[ulp];
    }
};

class Solution
{
private:
    bool isValid(int r, int c, int n, int m)
    {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        int countOne = 0,countZero = 0;
        int n = grid.size();
        int m = grid[0].size();
        DisjointSet dj(n * m  );
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        // step 1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {countZero++;
                    continue;
                }
                  countOne++;
                for (int ind = 0; ind < 4; ind++)
                {
                    int nrow = i + delRow[ind];
                    int ncol = j + delCol[ind];
                    if (isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1)
                    {
                        int u = i * m + j;
                        int v = nrow * m + ncol;
                        dj.unionBySize(u, v);
                    }
                }
            }
        }
        if(countOne == n*m) return n*m;
        if(countZero == n*m)  return 1;
        // step 2
        int maximumSize = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                set<int> st;
                if (grid[i][j] == 1)
                    continue;

                for (int ind = 0; ind < 4; ind++)
                {
                    int nrow = i + delRow[ind];
                    int ncol = j + delCol[ind];

                    if (isValid(nrow, ncol, n, m) && grid[nrow][ncol] == 1)
                    {
                        st.insert(dj.findUParent(nrow*m + ncol));
                    }
                }
                int sizeSum = 0;
                for (auto it : st)
                {
                    sizeSum = sizeSum + dj.getComponentSize(it);
                }
                maximumSize = max(maximumSize, sizeSum + 1);
                st.clear();
            }
        }

        return maximumSize;
    }
};
