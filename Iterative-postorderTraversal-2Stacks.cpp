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

class Solution{
    public:
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left != NULL) st1.push(root->left);
            if (root->right != NULL) st1.push(root->right);
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};

int main() {
    // 1. Create a sample binary tree
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // 2. Create an instance of the Solution class
    Solution sol;
    
    // 3. Call the postorderTraversal function
    vector<int> result = sol.postorderTraversal(root);
    
    // 4. Print the result
    cout << "Post-order traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}