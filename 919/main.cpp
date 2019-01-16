#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

class CBTInserter {
    TreeNode* root_node;
    queue<TreeNode*> waiting_queue;
    bool left_or_right;
public:
    CBTInserter(TreeNode* root) {
        root_node = root;
        // transvers
        waiting_queue.push(root_node);
        left_or_right = true; // true is left, false is right
        while (true) {
            TreeNode * cur_node = waiting_queue.front();
            if (cur_node->left != nullptr) {
                waiting_queue.push(cur_node->left);
            }
            else {
                // find the first null ptr
                left_or_right = true;
                break;
            }

            if (cur_node->right != nullptr) {
                waiting_queue.push(cur_node->right);
            }
            else {
                left_or_right = false;
                break;
            }
            waiting_queue.pop();
        }
    }
    
    int insert(int v) {
        TreeNode * cur_node = waiting_queue.front();
        if (left_or_right) {
            cur_node->left = new TreeNode(v);
            waiting_queue.push(cur_node->left);
        }
        else {
            cur_node->right = new TreeNode(v);
            waiting_queue.push(cur_node->right);
            waiting_queue.pop();
        }
        left_or_right = !left_or_right;
        return cur_node->val;
    }
    
    TreeNode* get_root() {
        return root_node;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */


int main() {
    
    return 0;
}
