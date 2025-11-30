#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};


bool isBST(Node* root, int minVal, int maxVal) {
    if (root == NULL)
        return true;
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    return isBST(root->left, minVal, root->data) &&
           isBST(root->right, root->data, maxVal);
}

int main() {
    
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->right = new Node(20);

    if (isBST(root, INT_MIN, INT_MAX))
        cout << "The given tree is a BST.\n";
    else
        cout << "The given tree is NOT a BST.\n";

    return 0;
}
