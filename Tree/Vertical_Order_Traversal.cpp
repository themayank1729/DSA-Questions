#include <bits/stdc++.h>
#include "TreeCreation.cpp"
#define mp make_pair 

vector<int> verticalOrderTraversal(TreeNode *root)
{
   map<int,map<int,vector<int>>> nodes;
   queue<pair<TreeNode*,pair<int,int>>> q;
   vector<int>ans;
   if(root == NULL) return ans;

   q.push(mp(root,mp(0,0)));
   while (!q.empty())
   {
    pair<TreeNode*,pair<int,int>>temp = q.front();
    q.pop();

    TreeNode* node = temp.first;
    int horizontal_dist = temp.second.first;
    int level = temp.second.second;
    nodes[horizontal_dist][level].push_back(node->data);

    if(node->left) q.push(mp(node->left,mp(horizontal_dist-1,level+1)));
    
    if(node->right) q.push(mp(node->right,mp(horizontal_dist+1,level+1)));
   }
      
for(auto i  :nodes)
{
    for(auto j : i.second)
    {
        for(auto k : j.second)
        {
            ans.push_back(k);
        }
    }
}
return ans;

}