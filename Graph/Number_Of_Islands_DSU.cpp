#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int r, int c, int n, int m) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

public:
    vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {
        DisjointSet dj(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<int> ans;

        for (int i = 0; i < q.size(); i++) {
            int r = q[i][0];
            int c = q[i][1];

            if (visited[r][c] == 1) {
                ans.push_back(count);
                continue;
            }

            visited[r][c] = 1;
            count++;

            int node = r * m + c;

            for (int j = 0; j < 4; j++) {
                int nrow = r + delRow[j];
                int ncol = c + delCol[j];

                if (isValid(nrow, ncol, n, m) && visited[nrow][ncol] == 1) {
                    int adjNode = nrow * m + ncol;
                    if (dj.findUParent(node) != dj.findUParent(adjNode)) {
                        count--;
                        dj.unionBySize(node, adjNode);
                    }
                }
            }

            ans.push_back(count);
        }
        return ans;
    }
};
