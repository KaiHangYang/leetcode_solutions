#include <iostream>
#include <vector>

using namespace std;
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        vector<ListNode*> node_arr;
        ListNode* cur_node = head;
        while (cur_node != NULL) {
            node_arr.push_back(cur_node);
            cur_node = cur_node->next;
        }

        int n = node_arr.size();
        if (k % n == 0) {
            return head;
        }
        else {
            int end_idx = n - k % n - 1;
            cur_node = node_arr[end_idx + 1];
            node_arr[n-1]->next = head;
            node_arr[end_idx]->next = NULL;
            head = cur_node;
        }

        return head;
    }
};

int main() {

    return 0;
}