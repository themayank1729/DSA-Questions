#include<bits/stdc++.h>
#include"TreeCreation.cpp"


bool isLeaf(TreeNode* node)
{
    return  !(node->left || node->right ); 
}
void addLeftBoundary(TreeNode* root,vector<int>&res)
{
    TreeNode* node = root->left;
    while(node)
    {
        if(!isLeaf(node)) res.push_back(node->data);
        if(node->left) node = node->left;
        else node = node->right;
    }
}

void addRightBoundary(TreeNode* root,vector<int>&res)
{
    TreeNode* node = root->right;
    vector<int>temp;
    while(node)
    {
        if(!isLeaf(node)) temp.push_back(node->data);
        if(node->right) node = node->right;
        else node = node->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        res.push_back(temp[i]);
    }
}
void addLeaves(TreeNode* root,vector<int>& res)
{
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);

}
vector<int> printBoundary(TreeNode* root)
{
   vector<int> res;
   if(root == NULL ) return res;
   if(!isLeaf(root)) res.push_back(root->data);

   addLeftBoundary(root,res);
   addLeaves(root,res);
   addRightBoundary(root,res);
   return res;
}
int main()
{

}