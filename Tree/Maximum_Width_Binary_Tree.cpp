#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;

typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *, ll>> q;
    q.push({root, 0});
    ll maxWidth = 0;
    while (!q.empty())
    {
        int size = q.size();
        ll leftMost = q.front().second;
        ll rightMost = q.back().second;
        maxWidth = max(maxWidth, rightMost - leftMost + 1);
        while (size--)
        {
           
            TreeNode *node = q.front().first;
            ll index = q.front().second;
            q.pop();
            if (node->left)
                q.push({node->left, 2 * index + 1});
            if (node->right)
                q.push({node->right, 2 * index + 2});
        }
    }
    return maxWidth;
    }