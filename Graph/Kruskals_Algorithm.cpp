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
};
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> edgesCopy(edges.size(), vector<int>(3)); // {edgeWeight,{currentNode,currentNodeParent}}
        for (auto &it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            edgesCopy.push_back({wt, u, v});
        }
        sort(edgesCopy.begin(), edgesCopy.end());

        int sum = 0;
        vector<pair<int, int>> MST;
        DisjointSet dj(V);

        for (auto &it : edgesCopy)
        {
            if (dj.findUParent(it[1]) != dj.findUParent(it[2]))
            {
                dj.unionByRank(it[1], it[2]);
                sum += it[0];
                MST.push_back({it[1], it[2]});
            }
        }
        return sum;
    }
};