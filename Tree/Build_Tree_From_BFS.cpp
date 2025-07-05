#include <bits/stdc++.h>
#include "TreeCreation.cpp"
using namespace std;
void buildTreeFromLevelOrderTraversal(Node* &root)
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
int main()
{
    Node *root = NULL;
    // creating a Tree
    //   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    /*
    root = buildTree(root);
    cout << "Printing the level order traversal output \n ";
    BFS(root);
    cout << "Inorder traversal is  : ";
    InorderTraversal(root);
    cout << "Preorder traversal is : ";
    PreorderTraversal(root);
    cout << "Postorder traversal is : ";
    PostorderTraversal(root);
    */
     buildTreeFromLevelOrderTraversal(root);
     StandardOps::BFS(root);
}