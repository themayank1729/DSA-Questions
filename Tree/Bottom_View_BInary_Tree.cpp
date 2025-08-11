#include <bits/stdc++.h>
#include "TreeCreation.cpp"
#define mp make_pair 

vector<int> bottomView(TreeNode *root)
{
  map<int,int>bottomNode;
  vector<int>ans;
  if(root == NULL) return ans;
  queue<pair<TreeNode*,int>>q;
  q.push(mp(root,0));

  while(!q.empty())
  {
    pair<TreeNode*,int>temp = q.front();
    q.pop();
    TreeNode* node = temp.first;
    int horizontal_dist = temp.second;

    
        bottomNode[horizontal_dist] = node->data;

    if(node->left) q.push(mp(node->left,horizontal_dist-1));
    if(node->right) q.push(mp(node->right,horizontal_dist+1));
  }

  for (auto i  : topNode)
  {
     ans.push_back(i.second);
  }
  return ans;
}