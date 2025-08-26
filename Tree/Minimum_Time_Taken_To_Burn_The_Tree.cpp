#include <bits/stdc++.h>
#include "TreeCreation.cpp"
/// Tree has unique values if not parent will also be node

/*
Time Complexity = O(n) + O(n)

Space Complexity = O(n)
*/
void makeGraph(unordered_map<int, vector<int>> &adj, int parent, TreeNode *curr)  //Better Appproach
{
    if (!curr)
        return;
    if (parent != -1)
    {
        adj[curr->data].push_back(parent);
    }
    if (curr->left)
    {
        adj[curr->data].push_back(curr->left->data);
    }
    if (curr->right)
    {
        adj[curr->data].push_back(curr->right->data);
    }
    makeGraph(adj, curr->data, curr->left);
    makeGraph(adj, curr->data, curr->right);
}

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<int, vector<int>> adj;
    makeGraph(adj, -1, root);

    // aplying BFS

    queue<int> q;
    unordered_set<int> visited;
    q.push(start);
    visited.insert(start);
    int time = 0;

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            int curr = q.front();
            q.pop();

            for (int &neighbor : adj[curr])
            {
                if (visited.find(neighbor) == visited.end())
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        time++;
    }
    return time - 1;
}

