#include <iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n) {
 for (int i = 0; i < n / 2; i++) {
 int minIdx = i, maxIdx = i;
 for (int j = i; j < n - i; j++) {
 if (arr[j] < arr[minIdx])
 minIdx = j;
 if (arr[j] > arr[maxIdx])
 maxIdx = j;
 }
 swap(arr[i], arr[minIdx]);
 if (maxIdx == i) maxIdx = minIdx;
 swap(arr[n - i - 1], arr[maxIdx]);
 }
}
int main() {
 int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
 int n = sizeof(arr)/sizeof(arr[0]);
 improvedSelectionSort(arr, n);
 cout << "Sorted array: ";
 for (int i = 0; i < n; i++) cout << arr[i] << " ";
}