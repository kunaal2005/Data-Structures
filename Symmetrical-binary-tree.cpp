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
    bool symetricBinaryCheck(TreeNode* root) {
        return root == NULL || help(root->left, root->right);
    }

private:
    bool help(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) return left == right;
        
        if (left->val != right->val) return false;
        
        return help(left->left, right->right) && help(left->right, right->left);
    }
};

int main() {
    TreeNode* symmetricRoot = new TreeNode(1);
    symmetricRoot->left = new TreeNode(2);
    symmetricRoot->right = new TreeNode(2);
    symmetricRoot->left->left = new TreeNode(3);
    symmetricRoot->left->right = new TreeNode(4);
    symmetricRoot->right->left = new TreeNode(4);
    symmetricRoot->right->right = new TreeNode(3);

    TreeNode* nonSymmetricRoot = new TreeNode(1);
    nonSymmetricRoot->left = new TreeNode(2);
    nonSymmetricRoot->right = new TreeNode(2);
    nonSymmetricRoot->left->right = new TreeNode(3);
    nonSymmetricRoot->right->right = new TreeNode(3);

    Solution sol;

    bool isSymmetric = sol.symetricBinaryCheck(symmetricRoot);
    cout << "Is the first tree symmetric? " << (isSymmetric ? "Yes" : "No") << endl;

    bool isNonSymmetric = sol.symetricBinaryCheck(nonSymmetricRoot);
    cout << "Is the second tree symmetric? " << (isNonSymmetric ? "Yes" : "No") << endl;
    
    return 0;
}
