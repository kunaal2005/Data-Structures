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
    vector<vector<int>> PreInPostOrder(TreeNode* root){
        vector<int> Preorder,Inorder,Postorder;
        stack<pair<TreeNode*,int>> st;
        if (root == NULL) return {};
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it.second == 1){
                Preorder.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first->left != NULL){
                    st.push({it.first->left,1});
                }
            }
            else if(it.second == 2){
                Inorder.push_back(it.first->val);
                it.second++;
                st.push(it);
                
                if(it.first->right != NULL){
                    st.push({it.first->right,1});
                }
            }
            else{
                Postorder.push_back(it.first->val);
            }
        }
        vector<vector<int>> result;
        result.push_back(Preorder);
        result.push_back(Inorder);
        result.push_back(Postorder);

    return result;
    }
};

int main() {
    // 1. Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    /*
         Tree structure:
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */

    // 2. Create an instance of the Solution class
    Solution sol;
    
    // 3. Call the function to get all traversals
    vector<vector<int>> allTraversals = sol.PreInPostOrder(root);

    // 4. Print the results
    cout << "Preorder:  ";
    for (int val : allTraversals[0]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder:   ";
    for (int val : allTraversals[1]) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int val : allTraversals[2]) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}