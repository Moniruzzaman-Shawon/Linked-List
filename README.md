# Linked List in C++

## What is a Linked List?

A linked list is a linear data structure that allows the storage of data in non-contiguous memory locations. It is defined as a collection of nodes, where each node consists of:

1. **Value:** Stores the data of the node.
2. **Next Pointer:** Stores the address of the next node in the list.

### Key Differences Between Array and Linked List
| Feature                  | Array                       | Linked List                  |
|--------------------------|-----------------------------|------------------------------|
| **Fixed Size**           | Yes                        | No                           |
| **Memory Allocation**    | Sequential                 | Non-contiguous               |
| **Dynamic Growth**       | No                         | Yes                          |

## Dynamic Memory Allocation

In C++, dynamic memory allocation allows memory to be allocated or deallocated at runtime. 

- **Dynamic Node:** Memory for each node in a linked list is allocated dynamically.
- **Manual Deallocation:** The programmer must deallocate memory that is no longer in use to prevent memory leaks.

### Example: Printing a Linked List in C++

```cpp
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int value) : val(value), next(NULL) {}
};

// Function to traverse and print the linked list
void printLinkedList(Node* head) {
    Node* temp = head; // Take the head in a temporary pointer

    // Traverse until temp is null
    while (temp != NULL) {
        cout << temp->val << " "; // Print the current node's value
        temp = temp->next;        // Move to the next node
    }
    cout << endl;
}

int main() {
    // Example linked list: 1 -> 2 -> 3 -> NULL
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    printLinkedList(head);

    // Deallocate memory (manual cleanup)
    delete head->next->next;
    delete head->next;
    delete head;

    return 0;
}



This README format is structured for clarity and readability while being suitable for GitHub. Let me know if you'd like to tweak it further!

