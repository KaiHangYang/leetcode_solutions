#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }

        vector<RandomListNode*> nodes_array;
        unordered_map<RandomListNode*, int> nodes_indices;
        vector<RandomListNode*> new_nodes_array;

        int cur_index = 0;
        
        RandomListNode* cur_node = head;
        nodes_array.push_back(cur_node);
        nodes_indices[cur_node] = cur_index;

        new_nodes_array.push_back(new RandomListNode(nodes_array[0]->label));

        while (cur_node->next != nullptr) {
            nodes_array.push_back(cur_node->next);
            nodes_indices[cur_node->next] = ++cur_index;

            new_nodes_array.push_back(new RandomListNode(cur_node->next->label));

            cur_node = cur_node->next;
        }


        for (int i = 0; i < nodes_array.size(); ++i) {
            if (i != nodes_array.size() - 1) {
                new_nodes_array[i]->next = new_nodes_array[i+1];
            }

            if (nodes_array[i]->random != nullptr) {
                new_nodes_array[i]->random = new_nodes_array[nodes_indices[nodes_array[i]->random]];
            }
            else {
                new_nodes_array[i]->random = nullptr;
            }
        }

        return new_nodes_array[0];

    }
};


int main() {

    return 0;
}
