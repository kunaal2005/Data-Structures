#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution{
    public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        long long ans=0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long min_idx = q.front().second;
            long long first,last;
            for(int i=0; i<size; i++){
                long long cur_id = q.front().second - min_idx;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_id;
                if(i==size-1) last = cur_id;
                if(node->left) q.push({node->left, cur_id*2+1});
                if(node->right) q.push({node->right, cur_id*2+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    Solution sol;
    int width = sol.widthOfBinaryTree(root);

    cout << "Maximum width of the binary tree is: " << width << endl;

    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}