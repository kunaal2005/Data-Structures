#include <iostream>
#include <algorithm> // For std::max
#include <climits>   // For INT_MIN

using namespace std;

// TreeNode structure remains the same
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class remains the same
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

private:
    int maxPathDown(TreeNode* node, int &maxi) {
        if (node == nullptr) return 0;
        
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));

        maxi = max(maxi, left + right + node->val);
        return max(left, right) + node->val;
    }
};

int main() {
    // 1. Build the binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // 2. Create an instance of the Solution class
    Solution sol;

    // 3. Call the correct public function to calculate the max path sum
    int maxSum = sol.maxPathSum(root);

    // 4. Print the result with the correct description
    cout << "The binary tree is:" << endl;
    cout << "      3" << endl;
    cout << "     / \\" << endl;
    cout << "    9   20" << endl;
    cout << "       /  \\" << endl;
    cout << "      15   7" << endl;
    cout << "\nCalculated Maximum Path Sum: " << maxSum << endl;

    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}