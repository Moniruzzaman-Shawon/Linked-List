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

int findDifference(Node* head) {
  if (head == NULL) return 0; // Handle empty list case

  int maxVal = head->val;
  int minVal = head->val;

  Node* current = head;
  while (current != NULL) {
    if (current->val > maxVal) {
      maxVal = current->val;
    }
    if (current->val < minVal) {
      minVal = current->val;
    }
    current = current->next;
  }

  return maxVal - minVal;
}

int main(){
  Node* head = NULL;
  Node* tail = NULL;

  int val;
  while (cin >> val && val != -1) {
    Node* newNode = new Node(val);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int result = findDifference(head);
  cout << result << endl;

  // Free the allocated memory
  while (head) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}