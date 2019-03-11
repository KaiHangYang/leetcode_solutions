#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int N = s.size();
        unordered_map<char, bool> exist;
        queue<int> index_queue;

        if (s.size() == 0) {
            return 0;
        }
        int max_len = 0;

        for (int i = 0; i < N; ++i) {
            char c = s[i];

            if (!exist[c]) {
                index_queue.push(i);
                exist[c] = true;
                max_len = max(max_len, static_cast<int>(index_queue.size()));
            }
            else {
                while (s[index_queue.front()] != c) {
                    exist[s[index_queue.front()]] = false;
                    index_queue.pop();
                }
                index_queue.pop();
                index_queue.push(i);
            }
        }
        return max_len;
    }
};

int main() {

    Solution s;
    cout << s.lengthOfLongestSubstring("aabaab!bb");
    return 0;
}
