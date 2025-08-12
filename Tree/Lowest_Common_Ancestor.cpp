#include <bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;

TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
        return root;

    TreeNode *leftN = LCA(root->left, p, q);
    TreeNode *rightN = LCA(root->right, p, q);

    if (leftN != NULL && rightN != NULL)
        return root;
    if (leftN == NULL)
        return rightN;
    return leftN;
}