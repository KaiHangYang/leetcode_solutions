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
public:
    TreeNode* _buildTree(const vector<int>& preorder, int & pre_idx, vector<int>::iterator in_start, vector<int>::iterator in_end) {
        if (in_start >= in_end) {
            // there is no elements in the sub tree
            return nullptr;
        }

        TreeNode * cur_root = new TreeNode(preorder[pre_idx]);
        ++pre_idx;
        vector<int>::iterator root_iter = find(in_start, in_end, cur_root->val);
        cur_root->left = _buildTree(preorder, pre_idx, in_start, root_iter);
        cur_root->right = _buildTree(preorder, pre_idx, root_iter+1, in_end);

        return cur_root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // The main idear is preorder will pass the left root first.
        int pre_idx = 0;
        return _buildTree(preorder, pre_idx, inorder.begin(), inorder.end());
    }
};

int main() {
    vector<int> preorder({4, 1, 2 ,3});
    vector<int> inorder({1,2,3,4});
    Solution s;
    TreeNode * cur_tree = s.buildTree(preorder, inorder);
    return 0;
}
