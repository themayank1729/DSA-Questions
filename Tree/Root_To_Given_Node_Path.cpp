#include <bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;

bool getPath(TreeNode *root, vector<int> &arr, int x)
{
    if (root == NULL)
        return false;
    arr.push_back(root->data);
    if (root->data == x)
        return true;
    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
    {
        return true;
    }
    arr.pop_back();
    return false;
}

vector<int> returnPath(TreeNode *root, int x)
{
    vector<int> arr;
    getPath(root, arr, x);
    return arr;
}