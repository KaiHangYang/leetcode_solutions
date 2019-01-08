#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool str_cmp(const std::string & a, const std::string & b) {
    if (a.length() > b.length()) {
        return true;
    }
    else {
        return false;
    }
}
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), str_cmp);
        for (int i = 0; i < strs.size(); ++i) {
            int cur_len = strs[i].length();
            bool is_subseq = false;
            for (int j = 0; j < strs.size(); ++j) {
                if (j == i) {
                    continue;
                }
                else if (cur_len <= strs[j].length()) {
                    // check whether strs[i] is the subsquence of strs[j]
                    if (isSubsequence(strs[i], strs[j])) {
                        is_subseq = true;
                        break;
                    }
                }
                else {
                    break;
                }
            }

            if (!is_subseq) {
                return cur_len;
            }
        }

        return -1;
    }

    bool isSubsequence(const string & a, const string & b) {
        std::size_t cur_index = 0;
        for (int i = 0; i < a.size(); ++i) {
            std::size_t tmp_index = cur_index;
            tmp_index = b.find(a[i], tmp_index);

            if (tmp_index != string::npos) {
                cur_index = tmp_index + 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};

// benchmark 4ms
int main() {
    Solution s;
    std::vector<string> hh({"abcabc","abcabc","abcabc","abc","abc","cca"});
    std::cout << s.findLUSlength(hh) << std::endl;
    return 0;
}
