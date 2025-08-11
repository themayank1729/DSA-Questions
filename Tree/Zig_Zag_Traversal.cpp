#include <bits/stdc++.h>
#include "TreeCreation.cpp"

vector<int> zigZag(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            temp[index] = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        leftToRight = !leftToRight;
        for (auto i : temp)
        {
            res.push_back(i);
        }
    }
    return res;
}