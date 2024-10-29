#include <iostream>
#include <algorithm> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int findMaxValue(Node* node) {
    if (node == nullptr) {
        return INT_MIN;
    }

    int leftMax = findMaxValue(node->left);
    int rightMax = findMaxValue(node->right);

    return max(node->data, max(leftMax, rightMax));
}

int main() {
    Node* root = new Node(10);  
    root->left = new Node(20); 
    root->right = new Node(30); 
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    int maxValue = findMaxValue(root);
    cout << "Maximum value: " << maxValue << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
