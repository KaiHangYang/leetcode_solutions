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
    vector<TreeNode*> buildTree(int start, int stop) {
        vector<TreeNode*> result;
        for (int i = start; i < stop; ++i) {
            // i is the head
            vector<TreeNode*> left_childs = buildTree(start, i);
            vector<TreeNode*> right_childs = buildTree(i+1, stop);
            
            if (!left_childs.empty() && !right_childs.empty()) {
                for (auto left:left_childs) {
                    for (auto right:right_childs) {
                        TreeNode* tmp = new TreeNode(i + 1);
                        tmp->left = left;
                        tmp->right = right;
                        result.push_back(tmp);
                    }
                }
            }
            else if (!left_childs.empty()) {
                for (auto left:left_childs) {
                    TreeNode* tmp = new TreeNode(i + 1);
                    tmp->left = left;
                    result.push_back(tmp);
                }
            }
            else if (!right_childs.empty()) {
                for (auto right:right_childs) {
                    TreeNode* tmp = new TreeNode(i + 1);
                    tmp->right = right;
                    result.push_back(tmp);
                }
            }
            else {
                result.push_back(new TreeNode(i + 1));
            }
        }
        return result;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(0, n);
    }
};

int main() {
    return 0;
}