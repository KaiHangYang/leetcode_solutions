#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int ALPHA_COUNT = 26;

struct TrieNode {
    bool is_word;
    TrieNode * children[ALPHA_COUNT];

    TrieNode() {
        this->is_word = false;
        for (int i = 0; i < ALPHA_COUNT; ++i) this->children[i] = nullptr;
    }
};

class Trie {
    TrieNode* head;
public:
    /** Initialize your data structure here. */
    Trie() {
        this->head = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur_head = this->head;

        for (char c:word) {
            int index = c - 'a';
            if (!cur_head->children[index]) {
                cur_head->children[index] = new TrieNode();
            }
            cur_head = cur_head->children[index];
        }
        cur_head->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur_head = this->head;
        for (char c:word) {
            int index = c - 'a';
            if (!cur_head->children[index]) {
                return false;
            }
            cur_head = cur_head->children[index];
        }
        if (cur_head->is_word) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur_head = this->head;
        for (char c:prefix) {
            int index = c - 'a';
            if (!cur_head->children[index]) {
                return false;
            }
            cur_head = cur_head->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

int main() {
    return 0;
}
