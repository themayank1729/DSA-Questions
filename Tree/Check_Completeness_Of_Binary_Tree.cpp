#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

bool isCompleteTree_Using_BFS(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool have_seen_null = false; // have you seen null node in past

    while (!q.empty())
    {

        TreeNode *node = q.front();
        q.pop();
        if (node == NULL)
        {
            have_seen_null = true;
        }
        else
        {
            if (have_seen_null)
                return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}
/**************************************************************************************
 */

int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool dfs(TreeNode *root, int i, int totalNodes)
{
    if (root == NULL)
        return true;

    if (i > totalNodes)
        return false;

    return dfs(root->left, 2 * i, totalNodes) &&
           dfs(root->right, 2 * i + 1, totalNodes);
}

bool isCompleteTree(TreeNode *root) // using DFS
{
    // we can also represent binary tree in the form of array
    int totalNodes = countNodes(root);
    int i = 1;
    return dfs(root, i, totalNodes);
}