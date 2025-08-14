#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) {
                res.push_back(curr->val);
            }
            if (curr->left) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void addLeafNodes(TreeNode* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        if (root->left) {
            addLeafNodes(root->left, res);
        }
        if (root->right) {
            addLeafNodes(root->right, res);
        }
    }

    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) {
                temp.push_back(curr->val);
            }
            if (curr->right) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    vector<int> printBoundary(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        if (!isLeaf(root)) {
            res.push_back(root->val);
        }

        addLeftBoundary(root, res);
        addLeafNodes(root, res);
        addRightBoundary(root, res);

        return res;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->right->left->right = new TreeNode(9);

    Solution sol;
    vector<int> boundary = sol.printBoundary(root);

    cout << "Boundary Traversal: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}