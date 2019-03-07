#include <iostream>
#include <vector>
#include <queue>

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

class BSTIterator {
    queue<int> q;
public:

    void travel(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            q.push(root->val);
            return;
        }

        if (root->left != nullptr) {
            travel(root->left);
        }
        q.push(root->val);
        if (root->right != nullptr) {
            travel(root->right);
        }
    }

    BSTIterator(TreeNode* root) {
        q = queue<int>();
        if (root != nullptr) {
            travel(root);
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int num = q.front();
        q.pop();
        return num;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main() {

    return 0; 
}
