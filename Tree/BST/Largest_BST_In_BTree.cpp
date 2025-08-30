class NodeValue {
public:
    int minNode, maxNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubTreeHelper(TreeNode *root) {
        // empty tree is a BST of size 0
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);

        // get values from left and right subtree
        auto left = largestBSTSubTreeHelper(root->left);
        auto right = largestBSTSubTreeHelper(root->right);

        // current node is greater than max in left and smaller than min in right → it is a BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // otherwise return invalid markers so parent can't be BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBSTSubtree(TreeNode *root) {
        return largestBSTSubTreeHelper(root).maxSize;
    }
};
