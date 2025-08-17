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
    vector<int> solve(TreeNode* A, int B) {
        vector<int> arr;
        if (A == NULL) return arr;
        getPath(A, arr, B);
        return arr;
    }

private:
    bool getPath(TreeNode* root, vector<int> &arr, int x) {
        if (!root) return false;
        arr.push_back(root->val);
        if (root->val == x) return true;
        if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
            return true;
        }
        arr.pop_back();
        return false;
    }
};

void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << " -> ";
        }
    }
    cout << "]" << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;

    int targetNodeValue = 5;
    cout << "Finding path to node: " << targetNodeValue << endl;
    vector<int> path = sol.solve(root, targetNodeValue);

    cout << "Path: ";
    printVector(path);

    cout << "\n-------------------\n" << endl;

    int nonExistentNodeValue = 8;
    cout << "Finding path to node: " << nonExistentNodeValue << endl;
    vector<int> noPath = sol.solve(root, nonExistentNodeValue);

    cout << "Path: ";
    printVector(noPath);

    return 0;
}
