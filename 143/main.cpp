#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }

        vector<ListNode *> node_list;
        ListNode* cur_node = head;

        while (cur_node->next != nullptr) {
            node_list.push_back(cur_node->next);
            cur_node = cur_node->next;
        }

        int start = 0;
        int end = node_list.size() - 1;
        bool flag = false;
        
        cur_node = head;
        while (end >= start) {
            if (flag) {
                cur_node->next = node_list[start++];
            }
            else {
                cur_node->next = node_list[end--];
            }

            cur_node = cur_node->next;
            flag = !flag;
        }

        cur_node->next = nullptr;
    }
};

int main() {
    cout << "Test" << endl;
    return 0;
}
