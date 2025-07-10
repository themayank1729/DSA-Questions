#include <bits/stdc++.h> 
#include "TreeCreation.cpp"


vector<int> preorderTraversal(TreeNode* root)   // returns the vector of preordered elements 
{
    stack <TreeNode*>s;
    s.push(root);
    vector<int>ans;
    while(!s.empty())
    {
        TreeNode* node = s.top();
        s.pop();
        ans.push_back(node->data);
        if(node->right != NULL) s.push(node->right);
        if(node->left != NULL) s.push(node->left);
    }
    return ans;
}