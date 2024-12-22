#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;

  //Create a constructor Node
  Node(int val) {
    this->val = val;
    this->next = NULL;
  }
};

void removeDuplicate(Node* head) {
  Node* current = head;

  while (current != NULL) {
    Node* a = current;
    while (a->next != NULL) {
      if (a->next->val == current->val) {
        Node* temp = a->next;
        a->next = a->next->next;
        delete temp;
      }
      else {
        a = a->next;
      }
    }
    current = current->next;
  }
};

void printLinkedList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
};

Node* createListFromInput() {
  int value;
  cin >> value;

  if (value == -1) {
    return NULL;
  }
  Node* head = new Node(value);
  Node* current = head;

  while (true) {
    cin >> value;
    if (value == -1){
      break;
    }
    Node* newNode = new Node(value);
    current->next = newNode;
    current = current->next;
  }
  return head;
};

int main() {
  Node* head = createListFromInput();
  removeDuplicate(head);
  printLinkedList(head);

  while (head != NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}