#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;
class LFUCache {
    struct BNode {
        int key;
        BNode *left, *right;
        BNode():key(-1), left(NULL), right(NULL) {}
        BNode(int key):key(key), left(NULL), right(NULL) {}
    };

    unordered_map<int, int> _valmap;
    unordered_map<int, BNode*> _idxmap;
    
    int capacity;
    int num;
    
    stack<BNode*> node_pool;
    BNode *head, *tail;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->num = 0;
        for (int i = 0; i < this->capacity; ++i) {
            node_pool.push(new BNode());
        }
        head = new BNode();
        tail = new BNode();
        head->right = tail;
        tail->left = head;
    }
    ~LFUCache() {
        BNode *tmp;
        while (head != NULL) {
            tmp = head->right;
            delete head;
            head = tmp;
        }
        while (!node_pool.empty()) {
            delete node_pool.top();
            node_pool.pop();
        }
    }
    void update_least(int key) {
        BNode *cur_node = this->_idxmap[key];
        cur_node->left->right = cur_node->right;
        cur_node->right->left = cur_node->left;
        cur_node->left = head;
        cur_node->right = head->right;
        head->right = cur_node;
        cur_node->right->left = cur_node;
    }
    int get(int key) {
        if (this->_valmap.count(key)) {
            update_least(key);
            return this->_valmap[key];
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (this->capacity == 0) {
            return;
        }
        if (this->_valmap.count(key)) {
            this->_valmap[key] = value;
            // update_least(key);
        }
        else {
            if (this->num >= this->capacity) {
                // remove the least freq one and put the data in
                int key_to_delete = tail->left->key;
                this->_idxmap.erase(key_to_delete);
                this->_valmap.erase(key_to_delete);

                this->_idxmap[key] = tail->left;
                this->_valmap[key] = value;
                tail->left->key = key;
            }
            else {
                BNode * cur_node = node_pool.top();
                node_pool.pop();
                // insert into the tail
                cur_node->key = key;
                cur_node->right = tail;
                cur_node->left = tail->left;
                tail->left = cur_node;
                cur_node->left->right = cur_node;

                this->_idxmap[key] = cur_node;
                this->_valmap[key] = value;
                this->num += 1;
            }
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LFUCache cache(3);
    cache.put(2, 2);
    cache.put(1, 1);
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(2) << endl;
    cache.put(3, 3);
    cache.put(4,4);
    cout << cache.get(3) << endl;
    cout << cache.get(2) << endl;
    cout << cache.get(1) << endl;
    cout << cache.get(4) << endl;
    return 0;
}