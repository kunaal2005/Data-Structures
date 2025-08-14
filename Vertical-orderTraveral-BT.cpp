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
    vector<vector<int>> VerticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        if (root == nullptr) {
            return {};
        }

        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            nodes[x][y].insert(node->val);

            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.VerticalTraversal(root);

    for (const auto& col : result) {
        cout << "[ ";
        for (int val : col) {
            cout << val << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}