#include<bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode* searchBST(TreeNode* root,int val)
{
    while(root !=NULL && root->data != val)
    {
        root = val>root->data ? root->right : root->left ;
    }
    return root;
}