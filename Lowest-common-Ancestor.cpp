#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;

    TreeNode* p1 = root->left;
    TreeNode* q1 = root->right;
    TreeNode* lca1 = sol.lowestCommonAncestor(root, p1, q1);
    if (lca1 != nullptr) {
        cout << "LCA of " << p1->val << " and " << q1->val << " is " << lca1->val << endl;
    }

    TreeNode* p2 = root->left->left;
    TreeNode* q2 = root->left->right->right;
    TreeNode* lca2 = sol.lowestCommonAncestor(root, p2, q2);
    if (lca2 != nullptr) {
        cout << "LCA of " << p2->val << " and " << q2->val << " is " << lca2->val << endl;
    }

    delete root->left->right->right;
    delete root->left->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}