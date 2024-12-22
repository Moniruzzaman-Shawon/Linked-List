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

int findIndex(Node* head, int x) {
    int index = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->val == x) {
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        Node* head = NULL;
        Node* tail = NULL;

        int val;
        while (cin >> val && val != -1) {
            Node* newNode = new Node(val);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        int x;
        cin >> x;
        cout << findIndex(head, x) << endl;

        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
