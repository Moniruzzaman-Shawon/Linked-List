#include <bits/stdc++.h>
using namespace std;

class Node {
  public
  :
  int val;
  Node * next;

  //Create a constructor Node
  Node(int val) {
    this->val = val;
    this->next = NULL;
  }
};

void insertAtHead(Node*& head, int val) {
  Node* newNode = new Node(val);
  newNode->next = head;
  head = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
  Node* newNode = new Node(val);
  if (head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

void deleteAtIndex(Node*& head, Node*& tail, int index) {
  if (head == NULL) return;  // Empty list, nothing to delete

  if (index == 0) {
    Node* temp = head;
    head = head->next;
    if (head == NULL) {
      tail = NULL;
    }
    delete temp;
    return;
  }

  Node* current = head;
  int currentIndex = 0;

  while (current != NULL && currentIndex < index - 1) {
    current = current->next;
    currentIndex++;
  }

  if (current == NULL || current->next == NULL) {
    return;
  }

  Node* temp = current->next;
  current->next = temp->next;
  if (current->next == NULL) {
    tail = current;
  }
  delete temp;
}

void printList(Node* head) {
  if (head == NULL) {
    cout << endl;
    return;
  }
  Node* current = head;
  while (current != NULL) {
    cout << current->val << " ";
    current = current->next;
  }
  cout << endl;
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; ++i) {
    int X, V;
    cin >> X >> V;

    if (X == 0) {
      insertAtHead(head, V);
      if (tail == NULL) {
        tail = head;
      }
    }
    else if (X == 1) {
      insertAtTail(head, tail, V);
    }
    else if (X == 2) {
      deleteAtIndex(head, tail, V);
    }

    printList(head);
  }

  while (head != NULL) {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  return 0;
}
