#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevel[i] = node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            if (!leftToRight) {
                reverse(currentLevel.begin(), currentLevel.end());
            }

            result.push_back(currentLevel);
            leftToRight = !leftToRight;
        }

        return result;
    }
};

TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    return root;
}

void printResult(const vector<vector<int>>& result) {
    cout << "[" << endl;
    for (const auto& level : result) {
        cout << "  [";
        for (size_t i = 0; i < level.size(); ++i) {
            cout << level[i] << (i == level.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    TreeNode* root = createSampleTree();
    Solution sol;

    cout << "Performing Zigzag Level Order Traversal..." << endl;
    vector<vector<int>> result = sol.zigzagLevelOrder(root);
    
    printResult(result);

    deleteTree(root);
    
    return 0;
}