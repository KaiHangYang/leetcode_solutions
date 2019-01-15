#include <iostream>
#include <vector>
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == nullptr) {
            return 0;
        }

        if (root->val >= L && root->val <= R) {
            return root->val + rangeSumBST(root->left) + rangeSumBST(root->right);
        }
        else if (root->val < L) {
            return rangeSumBST(root->right);
        }
        else {
            return rangeSumBST(root->left);
        }
    }
};

int main() {

    return 0;
}
