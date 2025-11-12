#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    Node* search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        if (head)
            head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int target, int val) {
        Node* targetNode = search(target);
        if (!targetNode) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = targetNode->next;
        newNode->prev = targetNode;
        if (targetNode->next)
            targetNode->next->prev = newNode;
        targetNode->next = newNode;
    }

    void insertBefore(int target, int val) {
        Node* targetNode = search(target);
        if (!targetNode) {
            cout << "Node " << target << " not found.\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = targetNode;
        newNode->prev = targetNode->prev;
        if (targetNode->prev)
            targetNode->prev->next = newNode;
        else
            head = newNode;
        targetNode->prev = newNode;
    }

    void deleteNode(int val) {
        Node* temp = search(val);
        if (!temp) {
            cout << "Node " << val << " not found.\n";
            return;
        }
        if (temp == head)
            head = temp->next;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << val << " deleted.\n";
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList list;
    int choice, val, target;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete a node\n";
        cout << "6. Search for a node\n";
        cout << "7. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtBeginning(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtEnd(val);
                break;
            case 3:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert after " << target << ": ";
                cin >> val;
                list.insertAfter(target, val);
                break;
            case 4:
                cout << "Enter target value: ";
                cin >> target;
                cout << "Enter value to insert before " << target << ": ";
                cin >> val;
                list.insertBefore(target, val);
                break;
            case 5:
                cout << "Enter value to delete: ";
                cin >> val;
                list.deleteNode(val);
                break;
            case 6:
                cout << "Enter value to search: ";
                cin >> val;
                if (list.search(val))
                    cout << "Node " << val << " found.\n";
                else
                    cout << "Node " << val << " not found.\n";
                break;
            case 7:
                list.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
