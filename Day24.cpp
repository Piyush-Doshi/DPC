#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    vector<TreeNode*> tree(nodes.size(), nullptr);
    for (size_t i = 0; i < nodes.size(); ++i) {
        if (nodes[i] != -1) tree[i] = new TreeNode(nodes[i]);
    }
    int i = 0, j = 1;
    while (j < nodes.size()) {
        if (tree[i]) {
            tree[i]->left = (j < nodes.size() && tree[j]) ? tree[j] : nullptr;
            ++j;
            tree[i]->right = (j < nodes.size() && tree[j]) ? tree[j] : nullptr;
            ++j;
        }
        ++i;
    }
    return tree;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    vector<int> nodes = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    TreeNode* root = buildTree(nodes);
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    cout << lca->val << endl;
    return 0;
}
