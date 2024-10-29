#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* node) {
    if (node == nullptr) return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

int main() {
    Node* root = new Node(1); 
    root->left = new Node(2);  
    root->right = new Node(3); 
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
