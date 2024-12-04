#include <iostream>
#include <vector>
using namespace std;

// + structure for AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

void rangeSearch(Node* node, int L, int R, vector<int>& result) {
    if (!node) return;

    if (L < node->key) rangeSearch(node->left, L, R, result);
    if (L <= node->key && node->key <= R) result.push_back(node->key);
    if (R > node->key) rangeSearch(node->right, L, R, result);
}

int main() {
    int n;
    cout << "Enter the number of elements to insert: ";
    cin >> n;

    Node* root = nullptr;
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int L, R;
    cout << "Enter the range [L, R]: ";
    cin >> L >> R;

    vector<int> result;
    rangeSearch(root, L, R, result);

    cout << "Elements in the range [" << L << ", " << R << "]: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
