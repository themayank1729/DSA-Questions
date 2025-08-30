#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode* build(vector<int>&pre,int& i,int upper_bound)
{
    if(i == pre.size() || pre[i] > upper_bound ) return NULL;
    TreeNode* root = new TreeNode(pre[i++]);
    root->left = build(pre,i,root->data);
    root->right = build(pre,i,upper_bound) ;
    return root;
}

TreeNode* bstFromPreorder(vector<int>&pre)
{
    int i = 0;
    return build(pre,i,INT_MAX);
}