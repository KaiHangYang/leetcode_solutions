#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> n_letters(26, 0);
        vector<bool> is_in(26, false);
        string res("");

        for (char ch:s) {
            n_letters[ch-'a']++;
        }

        for (char ch:s) {
            --n_letters[ch-'a'];
            if (res.empty()) {
                res.push_back(ch);
                is_in[ch-'a'] = true;
                continue;
            }

            if (is_in[ch-'a']) {
                continue;
            }

            while (!res.empty() && res.back() > ch && n_letters[res.back()-'a'] > 0) {
                is_in[res.back()-'a'] = false;
                res.pop_back();
            }

            res.push_back(ch);
            is_in[ch-'a'] = true;
        }

        return res;
    }
};


int main() {
    Solution s;

    std::cout << s.removeDuplicateLetters("cbacdcbewfhajkdjhfqejrhkjadgadfajkehrjqhejhajdfhkqwerjakhdfc") << std::endl;

    return 0;
}
