#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return vector<int>();
        }

        unordered_map<TreeNode*, bool> visited;
        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            TreeNode* cur_node = s.top();
            s.pop();

            if (cur_node->right == nullptr && cur_node->left == nullptr || visited[cur_node]) {
                result.push_back(cur_node->val);
            }
            else {
                visited[cur_node] = true;
                if (cur_node->right != nullptr) {
                    s.push(cur_node->right);
                }
                s.push(cur_node);
                if (cur_node->left != nullptr) {
                    s.push(cur_node->left);
                }
            }
        }

        return result;
    }
};


int main() {
    return 0;
}
