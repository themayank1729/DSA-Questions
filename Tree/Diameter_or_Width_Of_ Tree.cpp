#include<bits/stdc++.h>
#include "TreeCreation.cpp"
int height(Node* root)
{
    if(root == NULL) {
        return 0;
    }
    int left  = height(root->left);
    int right = height(root->right);
    int ans = max(left,right)  + 1;
    return ans;
}

int Diameter(Node* root)
{
    if(root == NULL) return 0;

    int op1 = Diameter(root->left);
    int op2 = Diameter(root->right);
    int op3 = height(root->left)  + height(root->left) + 1;
    int ans = max(op1,max(op2,op3));
    return ans;
 }
int main()
{
    
}