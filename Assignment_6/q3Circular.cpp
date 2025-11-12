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
    // assuming that the element is present in the list

    if(tail==NULL){
        // empty list
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        // non empty list
        Node* current = tail;
        while(current->data != element){
            current = current->next;
        }
        // element found -> current is representing element wala node
        Node* temp = new Node(d);
        temp->next = current->next;
        current->next = temp;
    }
}

void print(Node* &tail){
    int count=0;
    if(tail == NULL) return;

    Node* temp = tail;
    do{
        count++;
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);
    cout << endl;
    cout << "Size of LL : "<<count <<endl;
}
int main(){
    Node* tail = NULL;

    InsertNode(tail,5,3);  // first insertion (empty list, so ignores element)
    InsertNode(tail,3,5);  // insert 5 after 3
    InsertNode(tail,5,7);
    print(tail);
    
    return 0;
} 
