#include <bits/stdc++.h>
#define MAX_SIZE 10 
using namespace std;
class Stack {
private:
    int arr[MAX_SIZE];
    int top;  

public:
    
    Stack() {
        top = -1;
    }

    void push(int data) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push more elements." << endl;
            return;
        }
        top++;
        arr[top] = data;
        cout << data << " pushed to stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << arr[top] << " popped from stack." << endl;
        top--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Or throw an exception in a more advanced program
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Is Empty" << endl;
        cout << "5. Is Full" << endl;
        cout << "6. Display" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                value = s.peek();
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;
            case 4:
                if (s.isEmpty())
                    cout << "Stack is empty." << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;
            case 5:
                if (s.isFull())
                    cout << "Stack is full." << endl;
                else
                    cout << "Stack is not full." << endl;
                break;
            case 6:
                s.display();
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
