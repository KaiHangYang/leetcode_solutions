#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode *odd_head = head, *even_head = head->next, *cur_node = head->next->next, *tmp=NULL;
        ListNode *odd_cur = odd_head, *even_cur = even_head;
        bool odd_flag = true;
        while (cur_node != NULL) {
            tmp = cur_node->next;
            if (odd_flag) {
                odd_cur->next = cur_node;
                odd_cur = odd_cur->next;
            }
            else {
                even_cur->next = cur_node;
                even_cur = even_cur->next;
            }
            odd_flag = !odd_flag;
            cur_node = tmp;
        }
        even_cur->next = NULL;
        odd_cur->next = even_head;
        return odd_head;
    }
};

int main() {
    
    ListNode *head = new ListNode(1), *cur = head;
    cur->next = new ListNode(2);cur = cur->next;
    cur->next = new ListNode(3);cur = cur->next;
    cur->next = new ListNode(4);cur = cur->next;
    cur->next = new ListNode(5);cur = cur->next;
    cur->next = new ListNode(6);cur = cur->next;
    cur->next = new ListNode(7);cur = cur->next;
    // head is NULL, head is 1->NULL head is 1->2->NULL or other
    Solution s;
    ListNode *result = s.oddEvenList(head);

    while (result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}