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

/************ Pay attention to the negative nodes ***************?
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> cur_path;
    vector<vector<int>> all_paths;
    int target_sum;

public:
    void dfs(TreeNode* root, int cur_sum) {
        if (cur_sum == target_sum && root->right == nullptr && root->left == nullptr) {
            all_paths.push_back(cur_path);
        }

        if (root->left != nullptr) {
            cur_path.push_back(root->left->val);
            dfs(root->left, cur_sum + root->left->val);
            cur_path.pop_back();
        }

        if (root->right != nullptr) {
            cur_path.push_back(root->right->val);
            dfs(root->right, cur_sum + root->right->val);
            cur_path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        cur_path.clear();
        all_paths.clear();
        target_sum = sum;

        cur_path.push_back(root->val);
        dfs(root, root->val);

        return all_paths;
    }
};

int main() {
    cout << "test" << endl;
    Solution s;
    s.pathSum()
    return 0;
}
