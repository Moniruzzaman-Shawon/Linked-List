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

void SameToSame(Node* head1, Node* head2) {
  while (head1 != NULL && head2 != NULL) {
    if (head1->val != head2->val) {
      cout << "NO" << endl;
      return;
    }
    head1 = head1->next;
    head2 = head2->next;
  }

  // If one list is longer than the other
  if (head1 != NULL || head2 != NULL) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
}

int main() {
  Node* head1 = NULL;
  Node* tail1 = NULL;

  int val;
  while (cin >> val) {
    if (val == -1) break;
    Node* newNode = new Node(val);
    if (head1 == NULL) {
      head1 = newNode;
      tail1 = newNode;
    } else {
      tail1->next = newNode;
      tail1 = newNode;
    }
  }

  Node* head2 = NULL;
  Node* tail2 = NULL;

  while (cin >> val) {
    if (val == -1) break;
    Node* newNode = new Node(val);
    if (head2 == NULL) {
      head2 = newNode;
      tail2 = newNode;
    } else {
      tail2->next = newNode;
      tail2 = newNode;
    }
  }

  SameToSame(head1, head2);

  while (head1 != NULL) {
    Node* temp = head1;
    head1 = head1->next;
    delete temp;
  }

  while (head2 != NULL) {
    Node* temp = head2;
    head2 = head2->next;
    delete temp;
  }

  return 0;
}
