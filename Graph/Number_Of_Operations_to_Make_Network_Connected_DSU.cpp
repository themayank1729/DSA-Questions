
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    vector<int> getParent()
    {
        vector<int> compressed(parent.size());
        for (int i = 0; i < (int)parent.size(); i++)
        {
            compressed[i] = findUParent(i);
        }
        return compressed;
    }

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

/*
n = 4
m = 3
Edges = [ [0, 1] , [0, 2] , [1, 2] ]
*/

class Solution
{
public:
    int Solve(int n, vector<vector<int>> &edge) // mayank's solution
    {

        int m = edge.size();
        DisjointSet dj(n);
        for (auto it : edge)
        {
            dj.unionBySize(it[0], it[1]);
        }
        map<int, int> compo;

        // vector<int> parent = dj.getParent();

        for (int i = 0; i < n; i++)
        {

            compo[dj.findUParent(i)]++;
        }

        int totalEdgesReq = 0;
        for (auto it : compo)
        {
            totalEdgesReq += (it.second - 1);
        }

        int components = compo.size();

        if (components - 1 > m - totalEdgesReq)
        {
            return -1;
        }

        return components - 1;
    }
    int Solve(int n, vector<vector<int>> &edge) // striver's solution
    {
        // just count the extra edges if ultimate parent of u == ultimate parent of V   is happenning in loop while you traversing the edges , it will be the extra edge so count = count+ 1;
        int m = edge.size();
        DisjointSet dj(n);
        int extraEdges = 0;
        for (auto it : edge)
        {
            if (dj.findUParent(it[0]) != dj.findUParent(it[1]))
                dj.unionBySize(it[0], it[1]);
            else
                extraEdges += 1;
        }

        int components = 0;
        for (int i = 0; i < n; i++)
        {
            if (dj.findUParent(i) == i)
                components++;
        }

        if (extraEdges >= components - 1)
            return components - 1;
        return -1;
    }
};
