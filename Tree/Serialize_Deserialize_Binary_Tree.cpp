#include <bits/stdc++.h>
#include "TreeCreation.cpp"

string serialize(TreeNode* root) {
          if(!root) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        if(node == NULL)
        s.append("#,");
        else
        {
            s.append(to_string(node->data)+',');
        }
        if(node != NULL)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
  
    return s;
    }

    TreeNode* deserialize(string data) {
         if(data.size() == 0) return NULL;
         queue<TreeNode*>q;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    q.push(root);
    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str == "#") node->left = NULL;
        else
        {
           TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#") node->right == NULL ; 
        else
        {
           TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
    
    }

//************************************************************************ */
//Optimal solution
 TreeNode* decode(stringstream& ss) {
        string curr;
        if (!getline(ss, curr, ',')) return nullptr;    // guard for safety
        if (curr == "NULL") return nullptr;             // remove leading space

        TreeNode* root = new TreeNode(stoi(curr));
        root->left  = decode(ss);
        root->right = decode(ss);
        return root;
    }
 string serialize(TreeNode* root) {
        if (!root) return "NULL";
        // add commas between value, left, and right parts
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
