#include <iostream>
#include <vector>
#include <algorithm>

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
    vector<int> flipped_node;
    vector<int> voyage;
    int cur_pos;
    bool is_ok;
public:
    void dfs(TreeNode* root) {
        if (root != nullptr) {
            if (root->val != voyage[cur_pos++]) {
                is_ok = false;
                flipped_node.clear();
                flipped_node.push_back(-1);
                return;
            }

            if (cur_pos < voyage.size() && root->left != nullptr && root->left->val != voyage[cur_pos]) {
                // flip the node
                flipped_node.push_back(root->val);
                dfs(root->right);
                dfs(root->left);
            }
            else {
                dfs(root->left);
                dfs(root->right);
            }
        }
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        is_ok = true;
        cur_pos = 0;
        flipped_node.clear();
        this->voyage = voyage;

        dfs(root);

        return flipped_node;
    }
};

int main() {
    return 0;
}
