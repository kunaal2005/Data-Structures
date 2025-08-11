#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
    int maxi = 0;
    int maxDepth(TreeNode* root,int& maxi) {
        if (root == nullptr) {
            return 0;
        } else {
            int leftDepth = maxDepth(root->left, maxi);
            int rightDepth = maxDepth(root->right, maxi);
            maxi = max(maxi, leftDepth + rightDepth);
            return max(leftDepth,rightDepth)+1; 
        }
    }
};

int main() {
    // 1. Create a sample binary tree
    // The tree will look like this:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    // The longest path is 4 -> 2 -> 1 -> 3, which has a length of 3.
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 2. Create an instance of the Solution class
    Solution sol;

    // 3. Create a variable to hold the diameter result.
    // This variable will be passed by reference to the function.
    int diameter = 0;

    // 4. Call the function. It will return the height (which we can ignore)
    // and update the 'diameter' variable with the result.
    sol.maxDepth(root, diameter);

    // 5. Print the result
    cout << "The binary tree is:" << endl;
    cout << "       1" << endl;
    cout << "      / \\" << endl;
    cout << "     2   3" << endl;
    cout << "    / \\" << endl;
    cout << "   4   5" << endl;
    cout << "\nCalculated Diameter: " << diameter << endl; // Expected output: 3

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
