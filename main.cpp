// Linked list implementation in C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Creating a node
class Node {
   public:
  int value;
  Node* next;
};

void addNode(Node *head, int val)
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node;
    temp->next->value = val;
    temp->next->next = NULL;
}

void delNode(Node *head, int val)
{
    Node* temp = head;
    if(head->value == val)
    {
        head = head->next;
        delete temp;
    }
    else
    {
        temp = temp->next;
        Node* temp1 = head;
        while(temp!=NULL)
        {
            if(temp->value==val)
            {
                temp1->next = temp->next;
                delete temp;
                break;
            }
            else
            {
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
    }
}

int main() {
  Node* head;
  Node* one = NULL;
  Node* two = NULL;
  Node* three = NULL;

  // allocate 3 nodes in the heap
  one = new Node();
  two = new Node();
  three = new Node();

  // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // print the linked list value
  head = one;
  while (head != NULL) {
    cout << head->value;
    head = head->next;
  }
    
    //create a function to add a node
    addNode(head, 4);
    //create a function to delete a node
    delNode(head, 2);
}
