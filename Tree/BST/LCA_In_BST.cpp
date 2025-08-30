#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode *LCAInBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return NULL;
    if (root->data > p->data && root->data > q->data)
        return LCAInBST(root->left, p, q);
    if (root->data < p->data && root->data < q->data)
        return LCAInBST(root->right, p, q);
    return root;
}