#include <bits/stdc++.h>
#include "TreeCreation.cpp

bool check(TreeNode *node)
{
    return checkHeight(node) != -1;
}
int checkHeight(TreeNode *node)
{
    if (node == NULL)
        return 0;

    int leftHeight = checkHeight(node->left);
    if (leftHeight == -1)
        return -1;
    int rightHeight = checkHeight(node->right);
    if (rightHeight == -1)
        return -1;
    if(abs(leftHeight - rightHeight) > 1) return -1;    
    return max(leftHeight, rightHeight) + 1;
}