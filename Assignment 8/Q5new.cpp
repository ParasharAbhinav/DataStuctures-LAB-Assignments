#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSortIncreasing(int arr[], int n) {
   
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

   
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void heapSortDecreasing(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    
    heapSortIncreasing(arr, n);
    cout << "Sorted (Increasing): ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    
    int arr2[] = {12, 11, 13, 5, 6, 7};
    heapSortDecreasing(arr2, n);
    cout << "Sorted (Decreasing): ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    return 0;
}
