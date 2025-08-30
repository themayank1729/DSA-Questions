#include <bits/stdc++.h>
#include "TreeCreation.cpp"

TreeNode* findLastRight(TreeNode* root) {
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root) {
    if(root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    if(root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    TreeNode* newRoot = root->left;
    delete root;
    return newRoot;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->data == key) return helper(root);

    TreeNode* dummy = root;
    while(dummy != NULL) {
        if(dummy->data > key) {
            if(dummy->left != NULL && dummy->left->data == key) {
                dummy->left = helper(dummy->left);
                break;
            } else {
                dummy = dummy->left;
            }
        } else {
            if(dummy->right != NULL && dummy->right->data == key) {
                dummy->right = helper(dummy->right);
                break;
            } else {
                dummy = dummy->right;
            }
        }
    }
    return root;
}

///********************************************************************************************************** */
//second method

TreeNode* deleteFromBST(TreeNode* root,int val)
{
    if(root == NULL) return root;

    if(root->data == val)
    {
       //Three cases  - 0 child, 1 child, 2 child
       if(root->left == NULL && root->right == NULL)
       {
        delete root;
        return NULL;
       }
       if(root->left != NULL && root->right == NULL)
       {
          TreeNode* temp = root->left;
          delete root;
          return temp;
       }
       if(root->left == NULL && root->right != NULL)
       {
          TreeNode* temp = root->right;
          delete root;
          return temp;
       }
       //2 child
       if(root->left && root->right)
       {
        int mini = minVal(root->right)->data; //getting the minimum value from right subtree
        root->data = mini;
        root->right = deleteFromBST(root->right,mini);
        return root;
       }
       
    }
    else if(root->data > val)
    {
        root->left =  deleteFromBST(root->left,val);
        return root; 
    }
    else
    {
        root->right =  deleteFromBST(root->right,val);
        return root;
    }
}