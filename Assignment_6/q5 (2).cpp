#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};
void InsertNode(Node* &tail, int element, int d) {
    // Empty list
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;  // point to itself
    } 
    else {
        Node* current = tail;
        while (current->data != element) {
            current = current->next;
        }

        Node* temp = new Node(d);
        temp->next = current->next;
        current->next = temp;
        if (current == tail) {
            tail = temp;
        }
    }
}
void print(Node* tail) {
    if (tail == NULL) return;

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;

    // Traverse the list
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }


    if (temp == head)
        return true;

    return false;
}

int main() {
    Node* tail = NULL;

    InsertNode(tail, 5, 3);  // list: 3
    InsertNode(tail, 3, 5);  // list: 3 -> 5
    InsertNode(tail, 5, 7);  // list: 3 -> 5 -> 7 -> back to 3

    cout << "Linked List: ";
    print(tail);

    // Check if circular
    if (isCircular(tail->next))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is NOT circular." << endl;

    return 0;
}
