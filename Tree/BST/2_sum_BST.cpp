#include <bits/stdc++.h>
#include "TreeCreation.cpp"

class BSTIterator // this iterator  will work for both next as well as before
{
private:
    // reverse - true - > before
    // reverse - false - > next
    stack<TreeNode *> st;
    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if (!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);
        return temp->data;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node != NULL)
        {
            st.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        if (!l.hasNext() || !r.hasNext())
            return false;
        int i = l.next(); // next
        int j = r.next(); // before

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
            {
                if (l.hasNext())
                    i = l.next();
                else
                    break;
            }
            else
            {
                if (r.hasNext())
                    j = r.next();
                else
                    break;
            }
        }
        return false;
    }
}