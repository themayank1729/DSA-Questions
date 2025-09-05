#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<vector<int>> &adj)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dfs(it, visited, st, adj);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        //  V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

        vector<vector<int>> adj(V);
        // converting the edges vector into adjacency list which is adj
        for (auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        vector<int> visited(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, st, adj);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};