#include <iostream>
#include <algorithm> // For std::max

// Use the standard namespace to avoid prefixing with std::
using namespace std;

// =======================================================================
// DO NOT EDIT THE TreeNode STRUCTURE
// =======================================================================
/**
 * @brief Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// =======================================================================
// SOLUTION CLASS - WRITE YOUR ALGORITHM HERE
// =======================================================================
class Solution {
public:
    /**
     * @brief Calculates the maximum depth of a binary tree.
     * * The maximum depth is the number of nodes along the longest path
     * from the root node down to the farthest leaf node.
     * * @param root A pointer to the root of the binary tree.
     * @return The maximum depth of the tree.
     */
    int maxDepth(TreeNode* root) {
        // --- YOUR ALGORITHM GOES HERE ---
        //
        // Hint: A common approach is recursion.
        // The depth of a tree is 1 + the maximum depth of its left or right subtree.
        // What is the base case? (e.g., an empty tree)
        
        if (root == nullptr) {
            return 0;
        } else {
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            return max(leftDepth, rightDepth) + 1; 
        }
        
        // --- END OF YOUR ALGORITHM ---
    }
};

// =======================================================================
// DO NOT EDIT THE MAIN FUNCTION
// This part is for testing your code.
// =======================================================================
int main() {
    // 1. Create a sample binary tree
    // The tree will look like this:
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

    // 2. Create an instance of the Solution class
    Solution sol;

    // 3. Call your function to calculate the depth
    int depth = sol.maxDepth(root);

    // 4. Print the result
    cout << "The binary tree is:" << endl;
    cout << "      3" << endl;
    cout << "     / \\" << endl;
    cout << "    9  20" << endl;
    cout << "      /  \\" << endl;
    cout << "     15   7" << endl;
    cout << "\nCalculated Maximum Depth: " << depth << endl;


    // Clean up the allocated memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
