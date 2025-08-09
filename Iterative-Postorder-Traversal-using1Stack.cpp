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
    vector<int> PostorderTraversal(TreeNode* root){
        vector<int> postorder;
        if (root == NULL) return postorder;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* temp;
        while(cur!= NULL || !st.empty()){
            if(cur!=NULL){
                st.push(cur);
                cur = cur->left;
            }
            else{
                temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    postorder.push_back(temp->val);
                    st.pop();
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }else{
                    cur = temp;
                }
            }
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

    // 3. Call the PostorderTraversal function
    vector<int> result = sol.PostorderTraversal(root);

    // 4. Print the result
    cout << "Post-order traversal (1-stack): ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}