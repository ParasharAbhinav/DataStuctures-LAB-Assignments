#include <iostream>
#include <unordered_map>
using namespace std;
void countFrequency(int arr[], int n) {
 unordered_map<int, int> mp;
 for (int i = 0; i < n; i++)
 mp[arr[i]]++;
 cout << "Frequencies:\n";
 for (auto &p : mp) {
 cout << p.first << " -> " << p.second << " times\n";
 }
}
int main() {
 int nums[] = {2, 3, 2, 4, 3, 2};
 int n = sizeof(nums) / sizeof(nums[0]);
 countFrequency(nums, n);
 return 0;
}