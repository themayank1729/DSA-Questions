#include<bits/stdc++.h>
#include "TreeCreation.cpp"

class Solution {
    private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    private:

    void inorder(TreeNode* root)
    {
        if(!root) return;
        inorder(root->left);

         if(prev != NULL && (root->data < prev->data) )
         {
            //if this is the first violation, masrk  these two nodes as first and middle
            if(first == NULL)
            {
                first = prev;
                middle = root;
            }
            //If this  is the second violation
            else
            {
                last = root;
            }
         }
         //mark this node as previous
         prev = root;
         inorder(root->right);

    }

    public:

    void recoverTree(TreeNode* root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);     // do this prev = NULL
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && middle )
            swap(first->data,middle->data);
        
    }
};