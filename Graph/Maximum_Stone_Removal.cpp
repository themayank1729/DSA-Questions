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
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet dj(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            dj.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count = 0;
        for (auto it : stoneNodes)
        {
            if (dj.findUParent(it.first) == it.first)
            {
                count++;
            }
        }
        return n - count;
    }
};