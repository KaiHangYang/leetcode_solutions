#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    pair<int, int> cur_result;
public:
    void dfs(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL) {
            if (depth > cur_result.second) {
                cur_result.first = root->val;
                cur_result.second = depth;
            }
        }
        if (root->left) {
            dfs(root->left, depth+1);
        }
        if (root->right) {
            dfs(root->right, depth+1);
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        cur_result.first = root->val; // value
        cur_result.second = 0; // depth
        dfs(root, 0);

        return cur_result.first;
    }
};

int main() {

    return 0;
}
