#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode *inorderSuccessor_BST(TreeNode *root, TreeNode *p)
{
    TreeNode *successor = NULL;
    while (root != NULL)
    {

        if (p->data >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}