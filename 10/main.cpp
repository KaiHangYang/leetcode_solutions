#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> prev_dp(p.size() + 1, false);
        vector<bool> cur_dp(p.size() + 1, false);

        prev_dp[0] = true;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*') {
                if (i == 0) {
                    prev_dp[i+1] = true;
                }
                else {
                    prev_dp[i+1] = prev_dp[i-1];
                }
            }
        }

        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                if (p[j] == '.' || p[j] == s[i]) {
                    cur_dp[j+1] = prev_dp[j];
                }
                else if (p[j] == '*') {

                    if (j > 0) {
                        cur_dp[j+1] = cur_dp[j-1] || cur_dp[j] || ((prev_dp[j+1] || prev_dp[j]) && (s[i] == p[j-1] || p[j-1] == '.'));
                    }
                    else if (i > 0) {
                        cur_dp[j+1] = cur_dp[j];
                    }
                }
            }

            prev_dp = cur_dp;
            cur_dp = vector<bool>(p.size() + 1, false);
        }

        return prev_dp[p.size()];
 
    }
};

int main() {

    Solution s;

    cout << boolalpha << s.isMatch("aaa","ab*a");
    return 0;
}
