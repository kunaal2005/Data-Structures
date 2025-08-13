#include <iostream>
#include <algorithm> // For std::max
#include <stack>    // <--- ADD THIS
#include <utility>
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

class Solution {
public:
    // Recursive Approach.
    // bool CheckingIdenticalTrees(TreeNode* root1, TreeNode* root2) {

    //     if (root1 == nullptr || root2 == nullptr) {
    //         return root1 == root2;
    //     }

    //     return (root1->val == root2->val) &&
    //            CheckingIdenticalTrees(root1->left, root2->left) &&
    //            CheckingIdenticalTrees(root1->right, root2->right);
    // }
    // Iterative approach
    bool CheckingIdenticalTrees(TreeNode* root1, TreeNode* root2) {

        stack<pair<TreeNode*, TreeNode*>> nodeStack;
        nodeStack.push({root1, root2});

        while (!nodeStack.empty()) {

            // auto [n1, n2] = nodeStack.top(); // Works for C++ 17 only
            pair<TreeNode*, TreeNode*> currentPair = nodeStack.top();
            TreeNode* n1 = currentPair.first;
            TreeNode* n2 = currentPair.second;
            nodeStack.pop();

            if (!n1 && !n2) {
                continue;
            }

            if (!n1 || !n2 || n1->val != n2->val) {
                return false;
            }

            nodeStack.push({n1->right, n2->right});
            nodeStack.push({n1->left, n2->left});
        }
        return true;
    }
};

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


// ===================================================================
// 4. Main driver to run the tests
// ===================================================================
int main() {
    // --- Create sample trees ---

    // Tree 1: A simple binary tree
    TreeNode* tree1 = new TreeNode(10);
    tree1->left = new TreeNode(5);
    tree1->right = new TreeNode(15);
    // 

    // Tree 2: Identical to Tree 1
    TreeNode* tree2 = new TreeNode(10);
    tree2->left = new TreeNode(5);
    tree2->right = new TreeNode(15);
    // 

    // Tree 3: Different from Tree 1 (different value)
    TreeNode* tree3 = new TreeNode(10);
    tree3->left = new TreeNode(5);
    tree3->right = new TreeNode(99); // Different value here
    // 

    // --- Run the tests ---
    Solution sol;
    
    cout << "Testing if Tree 1 and Tree 2 are identical..." << endl;
    bool result1 = sol.CheckingIdenticalTrees(tree1, tree2);
    cout << "Result: " << boolalpha << result1 << " (Expected: true)" << endl;
    
    cout << "\nTesting if Tree 1 and Tree 3 are identical..." << endl;
    bool result2 = sol.CheckingIdenticalTrees(tree1, tree3);
    cout << "Result: " << boolalpha << result2 << " (Expected: false)" << endl;

    // --- Clean up allocated memory ---
    deleteTree(tree1);
    deleteTree(tree2);
    deleteTree(tree3);
    
    return 0;
}