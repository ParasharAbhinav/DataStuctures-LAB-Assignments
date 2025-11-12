#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularLinkedList {
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    Node* search(int val) {
        if (!tail) return nullptr;
        Node* temp = tail->next;  // head
        do {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        } while (temp != tail->next);
        return nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int target, int val) {
        Node* targetNode = search(target);
        if (!targetNode) {
            cout << "Node not found\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = targetNode->next;
        targetNode->next = newNode;
        if (targetNode == tail)
            tail = newNode;
    }

    void deleteNode(int val) {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;
        bool found = false;

        do {
            if (curr->data == val) {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);

        if (!found) {
            cout << "Node not found\n";
            return;
        }

        if (curr == prev) { // Only one node
            delete curr;
            tail = nullptr;
        } else {
            prev->next = curr->next;
            if (curr == tail) // deleting tail, update tail
                tail = prev;
            delete curr;
        }
        cout << "Node deleted\n";
    }

    void display() {
        if (!tail) {
            cout << "List is empty\n";
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "\n";
    }
};

int main() {
    CircularLinkedList list;
    int choice, val, target;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after node\n";
        cout << "4. Delete node\n";
        cout << "5. Search node\n";
        cout << "6. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value to insert: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Value to insert: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Insert after which value: ";
                cin >> target;
                cout << "Value to insert: ";
                cin >> val;
                list.insertAfter(target, val);
                break;
            case 4:
                cout << "Value to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 5:
                cout << "Value to search: ";
                cin >> val;
                if (list.search(val))
                    cout << "Found\n";
                else
                    cout << "Not found\n";
                break;
            case 6:
                list.display();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}

