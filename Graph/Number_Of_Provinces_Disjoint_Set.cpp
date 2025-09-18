#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> parent, size;

public:
    vector<int> getSize()
    {
        return size;
    }
    vector<int> getParent()
    {
        return parent;
    }
    DisjointSet(int n)
    {

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
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet dj(V);
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj.size(); j++)
            {
                if (adj[i][j] == 1)
                {
                  
                        dj.unionBySize(i, j);
                    
                }
            }
        }

        int count = 0;
        vector<int> parent = dj.getParent();
        for (int i = 0; i < V; i++)
        {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
};