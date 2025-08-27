vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> res;
    TreeNode *curr = root;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            res.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *leftChild = curr->left;
            while (leftChild->right != NULL)
            {
                leftChild = leftChild->right;
            }
            leftChild->right = curr;
            // curr->left can be deleted
            TreeNode *temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }
    }
    return res;
}