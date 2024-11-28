#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findDepth(Node* root, int value, int depth) {
    if (!root)
        return -1;

    if (root->data == value)
        return depth;

    int leftDepth = findDepth(root->left, value, depth + 1);
    if (leftDepth != -1)
        return leftDepth;

    return findDepth(root->right, value, depth + 1);
}

// Wrapper function
int getNodeDepth(Node* root, int value) {
    return findDepth(root, value, 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int value1 = 5;
    int depth1 = getNodeDepth(root, value1);
    cout << "Depth of " << value1 << ": " << depth1 << endl;

    int value2 = 6;
    int depth2 = getNodeDepth(root, value2);
    cout << "Depth of " << value2 << ": " << depth2 << endl;

    return 0;
}
