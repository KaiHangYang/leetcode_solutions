#include <iostream>
#include <vector>
#include <unordered_map>

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *cur_node = head, *prev_node;
        ListNode *head_node = new ListNode(-1);
        head_node->next = head;

        unordered_map<int, unsigned char> states;
        prev_node = head_node;
        while (cur_node != NULL) {
            if (states.count(cur_node->val)) {
                if (states[cur_node->val] == 1) {
                    prev_node->next = cur_node->next;
                    delete cur_node;
                    cur_node = prev_node->next;
                    continue;
                }
                else {
                    states[cur_node->val] = 1;
                }
            }
            else {
                states[cur_node->val] = 0;
            }
            prev_node = cur_node;
            cur_node = cur_node->next;
        }
        
        prev_node = head_node;
        cur_node = head_node->next;
        while (cur_node != NULL) {
            if (states[cur_node->val] == 1) {
                prev_node->next = cur_node->next;
                delete cur_node;
                cur_node = prev_node->next;
            }
            else {
                prev_node = cur_node;
                cur_node = cur_node->next;
            }
        }
        head = head_node->next;
        delete head_node;
        return head;
    }
};

int main() {
    ListNode *head = new ListNode(1), *cur=head;
    cur->next = new ListNode(2); cur = cur->next;
    cur->next = new ListNode(2); cur = cur->next;
    cur->next = new ListNode(2); cur = cur->next;
    // cur->next = new ListNode(2); cur = cur->next;
    Solution s;
    head = s.deleteDuplicates(head);
    if (head == NULL) {
        cout << "empty" <<endl;
        return 0;
    }
    while (head != NULL) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}