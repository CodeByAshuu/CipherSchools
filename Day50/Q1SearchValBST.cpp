#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool search(TreeNode* root, int target) {
    if (root == nullptr) {
        return false;
    }
    
    if (root->val == target) {
        return true;
    }
    
    return search(root->left, target) || search(root->right, target);
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int searchVal1 = 7;
    int searchVal2 = 20;

    cout << "Search for " << searchVal1 << ": " << (search(root, searchVal1) ? "true" : "false") << endl;
    cout << "Search for " << searchVal2 << ": " << (search(root, searchVal2) ? "true" : "false") << endl;

    return 0;
}
