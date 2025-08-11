#include <bits/stdc++.h>
#include "TreeCreation.cpp"

bool isSameTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    
    if(root1->data != root2->data) return false;
    bool l = isSameTree(root1->left, root2->left);
    bool r = isSameTree(root1->right, root2->right);
    return l && r;
}




bool isSameTree_BFS(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    
        queue<TreeNode*>que1;
        queue<TreeNode*>que2;
     que1.push(root1);
     que2.push(root2);

     while(!que1.empty() && !que2.empty())
     {
        TreeNode* node1 = que1.front(); que1.pop();
        TreeNode* node2 = que2.front(); que2.pop();

        if(node1->data != node2->data) return false;
        if(node1->left != NULL && node2->left != NULL)
        {
            que1.push(node1->left);
            que2.push(node2->left);
        }
        else if(node1->left != NULL || node2->left != NULL)
        {
             return false;
        }
         if(node1->right != NULL && node2->right != NULL)
        {
            que1.push(node1->right);
            que2.push(node2->right);
        }
        else if(node1->right != NULL || node2->right != NULL)
        {
             return false;
        }
        
     }
    return true;
}