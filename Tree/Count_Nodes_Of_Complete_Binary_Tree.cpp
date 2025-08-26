#include <bits/stdc++.h>
#include "TreeCreation.cpp"

/*
  Time Complexity  = O (logn) * O(logn)
  Space Complexity = O(logn)
*/


int getLeftHeight(TreeNode* root)
{
   TreeNode* temp = root;
    int height = 0;
   while(temp)
   {
    temp = temp->left;
    height++;
   }
   return height;
}
int getRightHeight(TreeNode* root)
{
    TreeNode* temp = root;
    int height = 0;
     while(temp)
   {
    temp = temp->right;
    height++;
   }
   return height;
}

int countNodes(TreeNode* root)
{
    if(root == NULL) return 0;
   int lh = getLeftHeight(root);
   int rh = getRightHeight(root);
   if(lh == rh)  //perfect binary tree
   return (pow(2,lh) - 1);
   
   return countNodes(root->left) + countNodes(root->right)  +1;
}
