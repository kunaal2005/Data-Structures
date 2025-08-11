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

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            if(leftDepth == -1 || rightDepth == -1) return -1;
            if(abs(max(leftDepth,rightDepth)) >1) return -1;
            return max(leftDepth,rightDepth)+1; 
        }
    }
};

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
    // root->right->left = new TreeNode(15);
    // root->right->right = new TreeNode(7);

    // 2. Create an instance of the Solution class
    Solution sol;

    // 3. Call your function to calculate the depth
    int depth = sol.maxDepth(root);

    // 4. Print the result
    cout << "The binary tree is:" << endl;
    cout << "      3" << endl;
    cout << "     / \\" << endl;
    cout << "    9  20" << endl;
    cout << "\nCalculated Maximum Depth: " << depth << endl;


    // Clean up the allocated memory
    // delete root->right->right;
    // delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
