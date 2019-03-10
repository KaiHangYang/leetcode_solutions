#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

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

struct COMP {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.first > b.first) {
            return true;
        }
        else if (a.first < b.first) {
            return false;
        }
        else {
            return a.second > b.second;
        }
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) {
            return vector<vector<int>>();
        }

        unordered_map<int, priority_queue<pair<int,int>, vector<pair<int,int>>, COMP>> arr;
        queue<pair<TreeNode*, int>> q;
        queue<int> level;
        q.push(pair<TreeNode*, int>(root, 0));
        level.push(0);

        while (!q.empty()) {
            pair<TreeNode*, int> cur_node = q.front();
            int cur_level = level.front();

            q.pop();
            level.pop();

            arr[cur_node.second].push(pair<int,int>(cur_level, cur_node.first->val));

            if (cur_node.first->left != nullptr) {
                level.push(cur_level+1);
                q.push(pair<TreeNode*, int>(cur_node.first->left, cur_node.second-1));
            }
            
            if (cur_node.first->right != nullptr) {
                level.push(cur_level+1);
                q.push(pair<TreeNode*, int>(cur_node.first->right, cur_node.second+1));
            }
        }

        vector<vector<int>> results;
        for (int i = -999; i < 999; ++i) {
            if (arr.count(i)) {
                vector<int> tmp;
                while (!arr[i].empty()) {
                    tmp.push_back(arr[i].top().second);
                    arr[i].pop();
                }

                results.push_back(tmp);
            }
        }

        return results;
    }
};

int main() {

    return 0;
}
