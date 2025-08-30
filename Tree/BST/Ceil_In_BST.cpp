#include <bits/stdc++.h>
#include "TreeCreation.cpp"

int ceil(TreeNode *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }
        else if (root->data > key)
        {
            ceil = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ceil;
}