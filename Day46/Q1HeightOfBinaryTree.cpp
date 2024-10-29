#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int calculateHeight(Node* node) {
    if (node == nullptr) {
        return -1;
    }
    
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3); 
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int height = calculateHeight(root);
    cout << "Height of the tree: " << height << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
