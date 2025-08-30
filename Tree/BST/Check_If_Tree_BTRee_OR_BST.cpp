#include <bits/stdc++.h>
#include "TreeCreation.cpp"

bool isValid(TreeNode *root, int mini, int maxi)
{
    if (root == NULL)
        return root;
    if (root->data < mini || root->data > max)
        return false;
    return isValid(root->left, mini, root->data) && isValid(root->right, root->data, maxi);
}

int main()
{
    bool ans = isValid(root, INT_MIN, INT_MAX);
}