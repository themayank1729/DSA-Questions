#include<bits/stdc++.h>
#include "TreeCreation.cpp"

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int ans = -1;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(cur->left == NULL) {
            // Visit this node
            count++;
            if(count == k) ans = cur->data;

            cur = cur->right;
        } else {
            // Find inorder predecessor
            TreeNode* pre = cur->left;
            while(pre->right != NULL && pre->right != cur) {
                pre = pre->right;
            }

            if(pre->right == NULL) {
                // Make thread
                pre->right = cur;
                cur = cur->left;
            } else {
                // Remove thread
                pre->right = NULL;
                count++;
                if(count == k) ans = cur->data;

                cur = cur->right;
            }
        }
    }
    return ans;
}