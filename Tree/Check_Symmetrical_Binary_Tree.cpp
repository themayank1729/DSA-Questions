#include <bits/stdc++.h>
#include "TreeCreation.cpp"

using namespace std;

// Forward declaration so compiler knows this function exists
bool isSymmetricHelp(TreeNode *root1, TreeNode *root2);

bool isSymmetry(TreeNode *root)
{
    return root == NULL || isSymmetricHelp(root->left, root->right);
}

bool isSymmetricHelp(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data)
        return false;

    bool l = isSymmetricHelp(root1->left, root2->right);
    bool r = isSymmetricHelp(root1->right, root2->left);
    return l && r;
}

int main()
{
    // You can test here
}
