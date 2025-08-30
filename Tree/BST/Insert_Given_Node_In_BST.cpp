#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode* insertBST(TreeNode* root,int val)
{
    if(!root) return new TreeNode(val);
    TreeNode* cur = root;

    while (1)
    {
        if(val >= root->data)
        {
            if(cur->right)  cur = cur->right;
            else
            {
                cur->right = new TreeNode(val);
                break;
            }
        } else
        {
            if(cur->left) cur = cur->left;
            else
            {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}