  unordered_map<TreeNode*,TreeNode*>parent;
    void setParent(TreeNode* root)
    {
      if(root == NULL) return;
      if(root->left) parent[root->left] = root;
      setParent(root->left);
      if(root->right) parent[root->right] = root;
      setParent(root->right);
    }
    void BFS(TreeNode* target,int k,vector<int>&result)
    {
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);
        while(!q.empty())
        {
            int n = q.size();
            if(k  == 0) break;
            while(n--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited.count(node->left->val))
                {
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                if(node->right && !visited.count(node->right->val))
                {
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                if(parent.find(node) != parent.end() && !visited
                .count(parent[node]->val))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]->val);
                }
               
            }
            k--;
        }
        while(!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;
        setParent(root);
        BFS(target,k,result);
        return result;
    }