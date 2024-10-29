#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int main() {
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);
  
    cout << "Root Node: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;
    cout << "Left child of node 2: " << root->left->left->data << endl;
    cout << "Right child of node 2: " << root->left->right->data << endl;

    //safayiii
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
