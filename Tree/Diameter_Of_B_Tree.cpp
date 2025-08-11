#include <bits/stdc++.h>
#include "TreeCreation.cpp"

int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = 0;
    height(root, diameter);
    return diameter;
}
//below function is gonna be private
int height(TreeNode *node, int &diameter)
{
    if (node == NULL)
        return 0;
    int leftHeight = height(node->left, diameter);
    int rightHeight = height(node->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
int main()
{
}