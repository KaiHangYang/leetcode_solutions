#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> postorder;
    vector<int> inorder;
    int pos;

public:
    TreeNode* _buildTree(vector<int>::iterator i_start, vector<int>::iterator i_end) {
        if (pos < 0 || i_start == i_end) {
            return nullptr;
        }

        TreeNode* cur_root = new TreeNode(postorder[pos]);
        --pos;

        auto mid_iter = find(i_start, i_end, cur_root->val);
        
        cur_root->right = _buildTree(mid_iter+1, i_end);
        cur_root->left = _buildTree(i_start, mid_iter);

        return cur_root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pos = postorder.size() - 1;
        this->inorder = inorder;
        this->postorder = postorder;

        return _buildTree(inorder.begin(), inorder.end());
    }
};

int main() {
    return 0;
}
