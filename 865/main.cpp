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

    vector<TreeNode *> cur_path;
    vector<vector<TreeNode *>> all_paths;
    int max_depth;
public:

    void dfs(TreeNode * root, int cur_depth) {
        if (root->left == nullptr && root->right == nullptr) {
            // till the leaf
            if (cur_depth >= max_depth) {
                if (cur_depth > max_depth) {
                    all_paths.clear();
                    max_depth = cur_depth;
                }
                all_paths.push_back(cur_path);
            }
            return;
        }

        if (root->left != nullptr) {
            cur_path.push_back(root->left);
            dfs(root->left, cur_depth + 1);
            cur_path.pop_back();
        }

        if (root->right != nullptr) {
            cur_path.push_back(root->right);
            dfs(root->right, cur_depth + 1);
            cur_path.pop_back();
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        // Use the DFS to solve this problem
        if (root == nullptr) {
            return nullptr;
        }
        max_depth = 0;
        cur_path.clear();
        all_paths.clear();

        cur_path.push_back(root);
        dfs(root, 0);

        for (int i = all_paths[0].size() - 1; i >= 0; --i) {
            TreeNode * cur_node = all_paths[0][i];
            bool all_equal = true;
            for (int j = 1; j < all_paths.size(); ++j) {
                if (all_paths[j][i] != cur_node) {
                    all_equal = false;
                    break;
                }
            }

            if (all_equal) {
                return cur_node;
            }
        }
    }
};

int main () {
    cout << "test" << endl;
    return 0;
}
