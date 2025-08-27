#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode *prev = NULL;

void flatten(TreeNode *root) // normal recursion
{
    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

//**************************************************************************************************************** */

void flatten(TreeNode *root)
{
    stack<TreeNode *> st;
    if (root)
        st.push(root);
    while (!st.empty())
    {
        TreeNode *cur = st.top();
        st.pop();

        if (cur->right)
            st.push(cur->right);
        if (cur->left)
            st.push(cur->left);

        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}

//**************************************************************************************d */

void flatten(TreeNode *root) // Optimal Approach - Morris Traversal
{
    TreeNode *cur = root;
    TreeNode *prev = NULL;
    while (cur != NULL)
    {
        if (cur->left != NULL)
        {
            prev = cur->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}