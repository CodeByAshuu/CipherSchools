#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findClosestValue(Node* root, int target) {
    int closest = root->data;

    while (root) {
        if (abs(target - root->data) < abs(target - closest))
            closest = root->data;

        if (target < root->data)
            root = root->left;
        else if (target > root->data)
            root = root->right;
        else
            break;
    }

    return closest;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);

    int target1 = 6;
    cout << "Closest value to " << target1 << ": " << findClosestValue(root, target1) << endl;

    int target2 = 8;
    cout << "Closest value to " << target2 << ": " << findClosestValue(root, target2) << endl;

    return 0;
}
