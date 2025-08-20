#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct BinaryTreeTreeNode {
    int val;
    BinaryTreeTreeNode *left;
    BinaryTreeTreeNode *right;
    BinaryTreeTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

BinaryTreeTreeNode* mapParentsAndFindTarget(BinaryTreeTreeNode* root, map<BinaryTreeTreeNode*, BinaryTreeTreeNode*> &parent_track, int start) {
    queue<BinaryTreeTreeNode*> q;
    q.push(root);
    BinaryTreeTreeNode* targetNode = nullptr;
    
    while (!q.empty()) {
        BinaryTreeTreeNode* node = q.front();
        q.pop();

        if (node->val == start) {
            targetNode = node;
        }

        if (node->left) {
            parent_track[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent_track[node->right] = node;
            q.push(node->right);
        }
    }
    return targetNode;
}

int timeToBurnTree(BinaryTreeTreeNode* root, int start) {
    if (root == nullptr) {
        return 0;
    }

    map<BinaryTreeTreeNode*, BinaryTreeTreeNode*> parent_track;
    BinaryTreeTreeNode* target = mapParentsAndFindTarget(root, parent_track, start);

    if (target == nullptr) {
        return 0;
    }

    map<BinaryTreeTreeNode*, bool> visited;
    queue<BinaryTreeTreeNode*> q;

    q.push(target);
    visited[target] = true;
    int time = 0;

    while (!q.empty()) {
        int level_size = q.size();
        bool burned_on_this_level = false;

        for (int i = 0; i < level_size; ++i) {
            BinaryTreeTreeNode* current = q.front();
            q.pop();

            if (current->left && !visited[current->left]) {
                burned_on_this_level = true;
                visited[current->left] = true;
                q.push(current->left);
            }

            if (current->right && !visited[current->right]) {
                burned_on_this_level = true;
                visited[current->right] = true;
                q.push(current->right);
            }

            if (parent_track[current] && !visited[parent_track[current]]) {
                burned_on_this_level = true;
                visited[parent_track[current]] = true;
                q.push(parent_track[current]);
            }
        }
        
        if (burned_on_this_level) {
            time++;
        }
    }

    return time;
}

int main() {
    BinaryTreeTreeNode* root = new BinaryTreeTreeNode(1);
    root->left = new BinaryTreeTreeNode(2);
    root->right = new BinaryTreeTreeNode(3);
    root->left->left = new BinaryTreeTreeNode(4);
    root->left->left->left = new BinaryTreeTreeNode(7);
    root->right->left = new BinaryTreeTreeNode(5);
    root->right->right = new BinaryTreeTreeNode(6);

    int startNodeValue = 2;
    int totalTime = timeToBurnTree(root, startNodeValue);

    cout << "Time to burn the entire tree starting from node " << startNodeValue << " is: " << totalTime << " minutes." << endl;

    return 0;
}