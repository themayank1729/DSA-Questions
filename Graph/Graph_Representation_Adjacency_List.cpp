#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {2, 1}, {3, 1}};
    map<int, vector<int>> adj;

    for (vector<int> &vec : prerequisites)
    {
        int u = vec[0];
        int v = vec[1];
        adj[u].push_back(v);
    }
}

// Space COmplexity  - O(v+e)