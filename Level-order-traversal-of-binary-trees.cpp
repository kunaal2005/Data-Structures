#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans; // Return empty vector if the tree is empty

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                
                // Add children to the queue if they exist
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);

                // Add the current node's value to the current level vector
                level.push_back(node->val);
            }
            // Add the completed level to the final answer
            ans.push_back(level);
        }
        return ans;
    }
};

/**
 * Helper function to print the 2D vector result.
 */
void printResult(const vector<vector<int>>& result) {
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/**
 * Main function to create a tree and test the levelOrder method.
 */
int main() {
    // Creating a sample binary tree:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create a Solution object and get the level order traversal
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    // Print the result
    cout << "Level Order Traversal: " << endl;
    printResult(result);

    // Clean up allocated memory (important in larger applications)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}