#include <bits/stdc++.h>
#include "TreeCreation.cpp"
int maxSum = 0;
int maxPathSum(TreeNode *root)
{
    maxSum = INT_MIN;
    solve(root);
    return maxSum;
}

int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int neeche_hi_milgaya_answer = l + r + root->data; // 1
    int koi_ek_accha = max(l.r) + root->data;          // 2
    int only_root_accha = root->data;                  // 3
    maxSum = max({maxSum, neeche_hi_milgaya_answer, koi_ek_accha, only_root_accha});

    return max({only_root_accha, koi_ek_accha});
}