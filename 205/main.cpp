#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> s_num;
        unordered_map<char, int> t_num;

        int s_count = 1;
        int t_count = 1;

        if (s.length() != t.length()) {
            return false;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (s_num.count(s[i]) == 0) {
                s_num[s[i]] = s_count++;
            }
            if (t_num.count(t[i]) == 0) {
                t_num[t[i]] = t_count++;
            }

            if (s_num[s[i]] != t_num[t[i]]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

    return 0;
}
