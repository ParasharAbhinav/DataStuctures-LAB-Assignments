#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[i] > heap[parent]) {
                swap(heap[i], heap[parent]);
                i = parent;
            } else break;
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Removed: " << heap[0] << "\n";
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }

    void display() {
        cout << "Priority Queue: ";
        for (int x : heap) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(50);
    pq.push(40);

    pq.display();

    cout << "Top element: " << pq.top() << "\n";

    pq.pop();
    pq.display();

    pq.pop();
    pq.display();

    return 0;
}
