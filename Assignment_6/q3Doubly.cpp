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

    void display() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        cout << "Size of LL : " <<count <<endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.insertAtBeginning(40);
    list.display();
    return 0;
}
