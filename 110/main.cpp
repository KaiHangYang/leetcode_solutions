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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int subtree_depth(TreeNode* root, bool &is_balanced) {
        if (!is_balanced) {
            return 0;
        }

        if (root == nullptr) {
            return 0;
        }
        
        int left_depth = subtree_depth(root->left, is_balanced);
        int right_depth = subtree_depth(root->right, is_balanced);

        if (is_balanced) {
            if (abs(left_depth - right_depth) > 1) {
                is_balanced = false;
                return 0;
            }

            return 1+max(left_depth, right_depth);
        }
        return 0;
    }

    bool isBalanced(TreeNode* root) {
        bool is_balanced = true;
        subtree_depth(root, is_balanced);

        return is_balanced;
    }
};

int main() {
    cout << "test" << endl;
    return 0;
}
