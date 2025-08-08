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
    vector<int> preorderTraversal(TreeNode *root){
        vector<int> preorder;
        if(root == NULL) return preorder;
        stack<TreeNode*> st;

        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left != NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};

int main() {
    // Creating a sample binary tree:
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Create a Solution object
    Solution sol;
    
    // Get the preorder traversal result
    vector<int> result = sol.preorderTraversal(root);

    // Print the result to the console
    cout << "Preorder Traversal: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // Clean up allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
