#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }

private:
    void recursion(TreeNode* root, int level, vector<int> &res) {
        if (root == NULL) return;
        
        if (res.size() == level) {
            res.push_back(root->val);
        }
        
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;

    vector<int> result = sol.rightSideView(root);

    cout << "Right Side View: ";
    printVector(result);

    return 0;
}


// The logic for the left side view is smiliar to the logic of right side view.