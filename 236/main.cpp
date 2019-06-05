#include <iostream>
#include <vector>

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
    vector<TreeNode*> cur_path;
    void dfs(TreeNode* node, int target1, int target2, vector<vector<TreeNode*>>& nodes_path) {
        if (node->val == target1 || node->val == target2) {
            nodes_path.push_back(cur_path);
        }
        if (nodes_path.size() == 2) {
            return;
        }

        if (node->left != NULL) {
            cur_path.push_back(node->left);
            dfs(node->left, target1, target2, nodes_path);
            cur_path.erase(cur_path.end() - 1);
        }

        if (node->right != NULL) {
            cur_path.push_back(node->right);
            dfs(node->right, target1, target2, nodes_path);
            cur_path.erase(cur_path.end() - 1);
        }
        return;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        vector<vector<TreeNode*>> nodes_path;
        cur_path.clear();
        cur_path.push_back(root);

        dfs(root, p->val, q->val, nodes_path);
        
        int min_len = min(nodes_path[0].size(), nodes_path[1].size());
        TreeNode* same_parent;
        for (int i = 0; i < min_len; ++i) {
            if (nodes_path[0][i] != nodes_path[1][i]) {
                break;
            }
            else {
                same_parent = nodes_path[0][i];
            }
        }

        return same_parent;
    }
};

int main() {

    return 0;
}