#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>

using namespace std;
class Solution {
    unordered_map<char, int> mp;
public:
    string minWindow(string s, string t) {
        mp.clear();
        
        string q;
        int min_len = numeric_limits<int>::max();
        string result;
        for (auto c:t) {
            tem[c]++;
        }

        for (auto c:s) {
            if (q.empty()) {
                if (tem.count(c)) {
                    mp[c]++;
                    q.push_back(c);
                    if (checkFull(t)) {
                        return string(1, q[0]);
                    }
                }
            }
            else {
                q.push_back(c);
                mp[c]++;
                while (!tem.count(q[0]) || mp[q[0]] > tem[q[0]]) {
                    mp[q[0]]--;
                    q.erase(q.begin());
                }
                if (checkFull(t)) {
                    if (min_len > q.size()) {
                        min_len = q.size();
                        result = q;
                    }
                }
            }
            
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("a", "aa");
    return 0;
}