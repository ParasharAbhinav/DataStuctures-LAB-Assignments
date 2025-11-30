struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* search_rec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

Node* search_itr(Node* root, int key) {
    Node* temp=root;
    while(temp){
        if(temp->data==x) return true;
       if(temp->data<x) temp=temp->right;
       else temp=temp->left;
    }
    return false;
}

int findMax(Node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}

int findMin(Node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

node* inorderSuccessor(node* root, node* x) {
    if (x->right) return findMin(x->right);
    
    node* succ = NULL;
    while(root) {
        if(x->data < root->data) {
            succ = root;    
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return succ;
}

node* inorderPredecessor(node* root, node* x) {
    if(x->left)
        return findMax(x->left);
    node* pred = NULL;
    while(root) {
        if(x->data > root->data) {
            pred = root;   
            root = root->right;
        }
        else if(x->data < root->data) {
            root = root->left;
        }
        else break;
    }
    return pred;
}
