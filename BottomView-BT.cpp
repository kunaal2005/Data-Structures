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

class Solution{
    public:
    vector<int> BottomView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        map<int,int> mapp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second;
            mapp[line] = node->val;
            if(node->left != NULL) q.push({node->left,line-1});
            if(node->right != NULL) q.push({node->right,line+1});
        }
        for(auto it: mapp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    Solution sol;
    vector<int> result = sol.BottomView(root);

    cout << "Bottom View of the binary tree is: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}