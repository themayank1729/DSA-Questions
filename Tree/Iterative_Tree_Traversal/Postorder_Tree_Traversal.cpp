#include <bits/stdc++.h> 
#include "TreeCreation.cpp"

vector<int> postorderTraversal(TreeNode *root)   //using one stack
{
    stack <TreeNode*>st;
    vector<int>ans;
    TreeNode* cur = root;
    while(cur != NULL || !st.empty())
    {
        if(cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            TreeNode* temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
   
    return ans;
}
vector<int> postorderTraversal_2Stack(TreeNode* root)
{
   vector<int>ans;
   if(root == NULL)   return ans;
   stack<TreeNode* > st1,st2;
   st1.push(root);
   while(!st1.empty())
   {
    root = st1.top();
    st1.pop();
    st2.push(root);
    if(root ->left != NULL)
    {
        st1.push(root->left);
    }
    if(root->right != NULL)
    {
        st1.push(root->right);
    }
    while(!st2.empty())
    {
        ans.push_back(st2.top()->data);
        st2.pop();
    }
}
return ans;
}