#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
vector<vector<int>> ans;
void fill(TreeNode *root, int sum, vector<int> temp, int &targetSum)
{
    if (root == NULL)
    {
        return;
    }
    sum = sum + root->data;
    temp.push_back(root->data);
    // checking if it is a leaf node
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == targetSum)
        {
            ans.push_back(temp);
        }
        return;
    }
    fill(root->left, sum, temp, targetSum);
    fill(root->right, sum, temp, targetSum);
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    vector<int> temp;
    fill(root, sum, temp, targetSum);
    return ans;
}

// see the comment of path sum 2 of codestorywithMIK youtube channel