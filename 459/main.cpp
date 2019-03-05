#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len_s = s.length();
        for (int p=2; p <= len_s; ++p) {
            if (len_s % p == 0) {
                // then check
                int len_sub = len_s / p;
                bool is_ok = true;
                for (int i = 1; i < p; ++i) {
                    if (s.substr(0, len_sub) != s.substr(i*len_sub, len_sub)) {
                        is_ok = false;
                        break;
                    }
                } 
                if (is_ok) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argv, char **argc) {
    Solution s;
    cout << boolalpha << s.repeatedSubstringPattern(string(argc[1]));

    return 0;
}
