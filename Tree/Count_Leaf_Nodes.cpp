#include <bits/stdc++.h>
#include "TreeCreation.cpp"

void countLeafNodes(Node *root, int &count)
{ // using Inorder Traversal
    if (root == NULL)
    {
        return;
    }
    countLeafNodes(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }
    countLeafNodes(root->right, count);
}
int main()
{
    Node *root = NULL;
    StandardOps::buildTreeFromLevelOrderTraversal(root);
    int count = 0;
    countLeafNodes(root, count);
    cout << count << " \n";
}