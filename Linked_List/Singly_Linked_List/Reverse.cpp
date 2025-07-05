#include <bits/stdc++.h>
#include "NodeCreation.cpp"
using namespace std;
Node* reverse(Node* head)
{
  Node* temp = head;
  if(temp == nullptr || temp->next == nullptr) return head;
  temp = reverse(temp->next);
  Node* newHead = temp;
  newHead->next = 

}
Node* reverse(Node* head)
{
  Node* temp = head;
  if(temp == nullptr || temp->next == nullptr) return head;
  temp = reverse(temp->next);
  Node* newHead = temp;
  newHead->next = 

}

int main()
{
    vector<int> arr = {2, 4, 5, 6, 7, 8};
    Node *head = StandardOps::arrayToLL(arr);
    StandardOps::printLL(head);


}