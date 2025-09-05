#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool dfs(int node, int col, vector<vector<int>> &graph, vector<int> &color)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (dfs(it, !col, graph, color) == false)
                    return false;
            }
            else if (color[node] == color[it])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> color(V, -1);
        int initialColor = 0;
        // since it can have V different components
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, initialColor, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};