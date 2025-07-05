#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class StandardOps
{
public:
 
    static void BFS(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        q.push(nullptr);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == nullptr)
            {
                cout << endl;
                if (!q.empty())
                    q.push(nullptr);
            }
            else
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
    }
    static Node *buildTree(Node *root)
    {
        cout << "Enter the data : " << endl;
        int data;
        cin >> data;
        root = new Node(data);
        if (data == -1)
        {
            return NULL;
        }
        cout << "Enter data for inserting in left of " << data << endl;
        root->left = buildTree(root->left);
        cout << "Enter the data for inserting in right of " << data << endl;
        root->right = buildTree(root->right);
        return root;
    }
    static void InorderTraversal(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        InorderTraversal(root->left);
        cout << root->data << " ";
        InorderTraversal(root->right);
    }
    static void PreorderTraversal(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
    static void PostorderTraversal(Node *root)
    {
        if (root == NULL)
            return;
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        cout << root->data << " ";
    }
    static void buildTreeFromLevelOrderTraversal(Node* &root)
{
  queue<Node*>q;
  cout<<"Enter the data for the root "<<endl;
  int data;
  cin>>data;
  root = new Node(data);
  q.push(root);
  while(!q.empty())
  {
    Node* temp = q.front();
    q.pop();
    cout<<"Enter left Node for "<<temp->data<<" ";
    int leftData;
    cin>>leftData;

    if(leftData != -1 )
    {
        temp->left = new Node(leftData);
        q.push(temp->left);
    }
    cout<<"Enter right Node for "<<temp->data<<" ";
    int rightData;
    cin>>rightData;

    if(rightData != -1 )
    {
        temp->right = new Node(rightData);
        q.push(temp->right);
    }
}
}
};
