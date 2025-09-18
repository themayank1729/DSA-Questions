//Position this line where user code will be pasted.
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }

    void dfs3(int node, vector<int>& vis, vector<vector<int>>& adjT, vector<int>& temp) {
        vis[node] = 1;
        for (auto it : adjT[node]) {
            if (!vis[it]) {
                dfs3(it, vis, adjT, temp);
            }
        }
        temp.push_back(node);
    }

public:
    pair<int, vector<vector<int>>> kosaraju(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);
        stack<int> st;

        // Step 1: Order vertices by finish time
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Step 2: Build transpose graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++) {
            vis[i] = 0; // reset visited
            for (auto it : adj[i]) {
                adjT[it].push_back(i);
            }
        }

        // Step 3: Process stack
        int countScc = 0;
        vector<vector<int>> scc;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                vector<int> temp;
                dfs3(node, vis, adjT, temp);
                countScc++;
                scc.push_back(temp);  // ✅ push only valid SCCs
            }
        }

        return {countScc, scc};  // return both count and components
    }
};
