#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root->val;
}

int main() {
    TreeNode* root1 = new TreeNode(20);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(30);
    root1->left->left = new TreeNode(5);
    root1->left->right = new TreeNode(15);

    cout << "Minimum value in the first BST: " << findMin(root1) << endl;

    TreeNode* root2 = new TreeNode(50);
    root2->left = new TreeNode(40);
    root2->left->left = new TreeNode(30);

    cout << "Minimum value in the second BST: " << findMin(root2) << endl;

    return 0;
}
