void changeTree(TreeNode *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right)
        root->data = tot;
}

/*
We want every node to satisfy the children sum property:

node->data = (left child’s data) + (right child’s data)


if it has children.

🔑 Why post-order correction is needed

Let’s walk through what happens:

Top-down phase (before recursion)

You compare root->data with the sum of its children.

If children are too small, you push root’s value down to children.

This ensures that no child is ever less than the parent’s value, maintaining feasibility.

✅ At this point, children may not yet follow the children sum property — they just have "adjusted values" that will be fixed later.

Recursive calls

You recurse into left and right subtrees.

Inside those calls, the same rule applies, and children in deeper levels are corrected further.

By the time recursion comes back, all subtrees are fixed.

Post-order correction (after recursion)

int tot = 0;
if (root->left)  tot += root->left->data;
if (root->right) tot += root->right->data;
if (root->left || root->right)
    root->data = tot;


Now, the children of the current node are already valid (they satisfy the property).

But the parent itself may still not equal the new sum of its children (since their values might have changed during recursion).

So, you recalculate parent’s value to exactly match its children.

🔥 This final correction ensures the property is satisfied bottom-up.

📌 Example

Consider this tree:

        50
       /  \
      7    2
     / \  / \
    3  5 1  30


At the start: root = 50, children sum = 7 + 2 = 9 < 50.
→ Push 50 down: left = 50, right = 50.

Recurse on left subtree (50). After recursion, it gets adjusted to valid children sum.

Recurse on right subtree (50). After recursion, it also gets adjusted.

Finally, post-order correction updates root:

root->data = left->data + right->data


so the entire tree satisfies the children sum property.
*/