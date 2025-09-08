#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* node, long min, long max) {
    if (!node) return true;
    if (node->val <= min || node->val >= max) return false;
    return isBSTUtil(node->left, min, node->val) &&
           isBSTUtil(node->right, node->val, max);
}

bool isValidBST(TreeNode* root) {
    return isBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
