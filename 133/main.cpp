#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        Node* head = new Node(node->val, vector<Node*>());
        map<int, Node*> nodes_created;
        map<int, bool> copied;

        queue<Node*> waiting_queue;
        queue<Node*> raw_queue;

        waiting_queue.push(head);
        raw_queue.push(node);

        nodes_created[head->val] = head;

        while(!waiting_queue.empty()) {
            Node* new_node = waiting_queue.front();
            Node* raw_node = raw_queue.front();

            waiting_queue.pop();
            raw_queue.pop();

            if (!copied[new_node->val]) {
                copied[new_node->val] = true;
                
                for (Node* raw_child:raw_node->neighbors) {
                    if (nodes_created[raw_child->val] == nullptr) {
                        Node* tmp_node = new Node(raw_child->val, vector<Node*>());
                        nodes_created[raw_child->val] = tmp_node;
                        new_node->neighbors.push_back(tmp_node);
                    }
                    else {
                        new_node->neighbors.push_back(nodes_created[raw_child->val]);
                    }

                    if (!copied[raw_child->val]) {
                        raw_queue.push(raw_child);
                        waiting_queue.push(nodes_created[raw_child->val]);
                    }
                }
            }
        }

        return head;
    }
};

int main() {

    return 0;
}
