#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> q;
        int n_nodes = 0;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur_node = q.front();
            q.pop();

            if (cur_node == nullptr) {
                break;
            }

            ++n_nodes;
            q.push(cur_node->left);
            q.push(cur_node->right);
        }

        return n_nodes;
    }
};

int main() {
    return 0;
}
