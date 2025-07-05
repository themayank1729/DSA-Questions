#include<bits/stdc++.h>
#include"TreeCreation.cpp"

void countOfLeafNodes(Node* root,int &count)
{  // using Inorder Traversal
    if(root == NULL)
    {
        return;
    }
     countOfLeafNodes(root->left,count);
    if(root->left == NULL && root->right == NULL)
    {
      count++;
    }
    countOfLeafNodes(root->right,count);
}
int main()
{
    Node* root  = NULL;
     StandardOps::buildTreeFromLevelOrderTraversal(root);
     int count = 0;
     countOfLeafNodes(root,count);
     cout<<count<<" \n";
}