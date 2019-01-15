#include <iostream>
#include <vector>
#include <queue>

/***** Do things more carefull ******/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        queue<pair<Node *, int>> cur_array;
        vector<vector<int>> results;
        cur_array.push(pair<Node*, int>(root, 0));

        while (!cur_array.empty()) {
            pair<Node*, int> cur_node = cur_array.front();
            cur_array.pop();

            if (cur_node.second >= results.size()) {
                results.push_back(vector<int>());
            }
            results[cur_node.second].push_back(cur_node.first->val);

            for (int i = 0; i < cur_node.first->children.size(); ++i) {
                cur_array.push(pair<Node *, int>(cur_node.first->children[i], cur_node.second + 1));
            }
        }

        return results;
    }
};

