#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertNode(Node* &tail , int element, int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* current = tail;
        while(current->data != element){
            current = current->next;
        }
        Node* temp = new Node(d);
        temp->next = current->next;
        current->next = temp;
        // optionally update tail if inserted after tail
        if(current == tail) {
            tail = temp;
        }
    }
}

void print(Node* &tail){
    if(tail == NULL) return;

    Node* temp = tail->next;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail->next);
    cout << tail->next->data << endl;
}

int main(){
    Node* tail = NULL;

    InsertNode(tail,5,3);
    InsertNode(tail,3,5);
    InsertNode(tail,5,7);
    print(tail); 

    return 0;
}
