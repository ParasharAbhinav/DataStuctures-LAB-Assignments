#include <iostream>
using namespace std;

int binarySearchIterative(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;  // Element found
        else if (arr[mid] < target)
            low = mid + 1;  // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1; // Element not found
}

int main() {
    int arr[] = {2, 4, 7, 10, 23, 45, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearchIterative(arr, n, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result << "." << endl;
    else
        cout << "Element " << target << " not found in array." << endl;

    return 0;
}
