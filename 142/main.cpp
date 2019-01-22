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
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Floyd's cycle theory
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* slow_node = head;
        ListNode* fast_node = head;

        while (fast_node != nullptr && fast_node->next != nullptr) {
            slow_node = head->next;
            fast_node = fast_node->next->next;

            if (slow_node == fast_node) {
                // find the cycle
                while (head != slow_node) {
                    head = head->next;
                    slow_node = slow_node->next;
                }

                return head;
            }
        }
    }
};

int main() {
    ListNode* head = new ListNode(3);

    Solution s;
    //std::cout << s.detectCycle(head)->val << endl;

    return 0;
}
