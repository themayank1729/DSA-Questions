#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
void solve(TreeNode *root, vector<int> &ans, int level)
{
    if (root == nullptr)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(TreeNode *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
int main()
{
    
}