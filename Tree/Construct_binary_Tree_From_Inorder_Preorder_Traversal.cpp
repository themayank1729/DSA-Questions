#include <bits/stdc++.h>
#include "TreeCreation.cpp"
Node* solve(vector<int> &preOrder,vector<int> &inOrder,int start,int end, int& idx)
{
    if(start > end) return NULL;
    int rootVal = preOrder[idx];
    int i = start;
    for(;i<=end;i++)
    {
        if(inOrder[i] == rootVal) break;
    }
    idx++;
    TreeNode* root =  new TreeNode(rootVal);
    root->left = solve(preOrder,inOrder,start,i-1,idx);
    root->right  =solve(preOrder,inOrder,i+1,end,idx);
    return root;
}

//Time Complexity  - O(n*n) in worst case
//SC - O ( 1 )

Node* buildTree(vector<int> preOrder,vector<int> inOrder)
{
    int n = preOrder.size();
    int idx = 0;
    return solve(preOrder,inOrder,0,n-1,idx);
}

//***************************************************************************************************************************** */
//Optimal Approach

//Time Complexity  - O(n) in worst case
//Space Complexity  - O ( n ) map

TreeNode* buildTreeHelper(vector<int>& inOrder, vector<int>& postOrder,
                          unordered_map<int,int>& inMap,
                          int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = postOrder[postIndex--];
    TreeNode* root = new TreeNode(rootVal);

    // Get inorder index in O(1)
    int inIndex = inMap[rootVal];

    // Build right first (since postOrder is left → right → root)
    root->right = buildTreeHelper(inOrder, postOrder, inMap, inIndex + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inOrder, postOrder, inMap, inStart, inIndex - 1, postIndex);

    return root;
}

TreeNode* buildTree(vector<int>& inOrder, vector<int>& postOrder) {
    int n = inOrder.size();
    unordered_map<int,int> inMap;  // store inorder index for O(1) lookup

    for (int i = 0; i < n; i++) {
        inMap[inOrder[i]] = i;
    }

    int postIndex = n - 1;
    return buildTreeHelper(inOrder, postOrder, inMap, 0, n - 1, postIndex);
}
