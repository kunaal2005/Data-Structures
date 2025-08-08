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
    vector<int> inorderTraversal(TreeNode *root){
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true){
            if(node!= NULL){
                st.push(node);
                node = node->left;
            }else{
                if( st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
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
    
    // Get the inorder traversal result
    vector<int> result = sol.inorderTraversal(root);

    // Print the result to the console
    cout << "Inorder Traversal: [";
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