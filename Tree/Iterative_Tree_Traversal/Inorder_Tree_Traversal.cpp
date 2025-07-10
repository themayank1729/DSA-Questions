#include <bits/stdc++.h> 
#include "TreeCreation.cpp"

vector<int> getInOrderTraversal(TreeNode *root)
{
     stack <TreeNode*>s;
    vector<int>ans;
    TreeNode* node = root;
    while(true)
    {
        if(node != NULL)
        {
           s.push(node);
           node  = node->left;
        }
        else
        {
            if(s.empty() == true)
            {
                break;
            }
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}