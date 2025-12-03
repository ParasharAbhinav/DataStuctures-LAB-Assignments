#include <iostream>
#include <unordered_set>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) : data(val), left(NULL), right(NULL) {}
};
bool hasDuplicate(Node* root, unordered_set<int> &seen) {
 if (root == NULL) return false;
 if (seen.find(root->data) != seen.end())
 return true;
 seen.insert(root->data);
 return hasDuplicate(root->left, seen) || hasDuplicate(root->right, seen);
}
int main() {

 Node* root = new Node(5);
 root->left = new Node(3);
 root->right = new Node(7);
 root->left->left = new Node(2);
 root->left->right = new Node(3); 
 root->right->right = new Node(8);
 unordered_set<int> seen;
 if (hasDuplicate(root, seen))
 cout << "Duplicates Found";
 else
 cout << "No Duplicates";
 return 0;
}