#include <iostream>
#include <unordered_map>
using namespace std;
int firstNonRepeating(int arr[], int n) {
 unordered_map<int, int> freq;
 for (int i = 0; i < n; i++)
 freq[arr[i]]++;
 for (int i = 0; i < n; i++) {
 if (freq[arr[i]] == 1)
 return arr[i];
 }
 return -1; 
}
int main() {
 int arr[] = {4, 5, 1, 2, 0, 4};
 int n = sizeof(arr) / sizeof(arr[0]);
 int ans = firstNonRepeating(arr, n);
 if (ans == -1)
 cout << "No non-repeating element";
 else
 cout << ans;
 return 0;
}