#include <iostream>
#include <unordered_set>
using namespace std;
void printCommon(int A[], int n, int B[], int m) {
 unordered_set<int> s;
 for (int i = 0; i < n; i++)
 s.insert(A[i]);
 cout << "Common elements: ";
 for (int i = 0; i < m; i++) {
 if (s.find(B[i]) != s.end()) {
 cout << B[i] << " ";
 s.erase(B[i]); 
 }
 }
}
int main() {
 int A[] = {1, 2, 3, 4};
 int B[] = {3, 4, 5, 6};
 int n = sizeof(A) / sizeof(A[0]);
 int m = sizeof(B) / sizeof(B[0]);
 printCommon(A, n, B, m);
 return 0;
}