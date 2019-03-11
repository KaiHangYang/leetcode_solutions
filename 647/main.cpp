#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int N = s.size();
        for (int i = 0; i < N; ++i) {
            // check single center;
            for (int j = 0; j < N; ++j) {
                if (i - j >= 0 && i + j < N) {
                    if (s[i-j] == s[i+j]) {
                        ++cnt;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }

            // check double centers;
            if (i != N-1 && s[i] == s[i+1]) {
                for (int j = 0; j < N; ++j) {
                    if (i - j >= 0 && i + j + 1 < N) {
                        if (s[i-j] == s[i+j+1]) {
                            ++cnt;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("leetcode");
    return 0;
}
