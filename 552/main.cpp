#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
dp[n][2][3]
dp[n][0][0]: 表示0个缺席、前面一个不是迟到
dp[n][0][1]: 表示0个缺席、前面一个是缺席，并且前前一个不是缺席
dp[n][0][2]: 表示0个缺席、前面两个都是缺席
dp[n][1][0]: 表示1个缺席、前面一个不是迟到
dp[n][1][1]: 表示1个缺席、前面一个是迟到，并且前前一个不是迟到
dp[n][1][2]: 表示1个缺席、前面两个都是迟到（前前前一个不是迟到）
 */
class Solution {
public:
    int checkRecord(int n) {
        // dp[n][2][3]
        vector<vector<vector<unsigned int>>> dp(2, vector<vector<unsigned int>>(2, vector<unsigned int>(3, 0)));
        dp[0][0][0] = 1; dp[0][0][1] = 1; dp[0][0][2] = 0;
        dp[0][1][0] = 1; dp[0][1][1] = 0; dp[0][1][2] = 0;
        unsigned int mod_val = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            dp[1][0][0] = (dp[0][0][0] + dp[0][0][1] + dp[0][0][2]) % mod_val;
            dp[1][0][1] = dp[0][0][0];
            dp[1][0][2] = dp[0][0][1];

            dp[1][1][0] = ((dp[0][0][0] + dp[0][0][1] + dp[0][0][2]) % mod_val + \
                          (dp[0][1][0] + dp[0][1][1] + dp[0][1][2]) % mod_val) % mod_val;
            dp[1][1][1] = dp[0][1][0];
            dp[1][1][2] = dp[0][1][1];
            dp[0] = dp[1];
        }
        int res = ((dp[0][0][0] + dp[0][0][1] + dp[0][0][2]) % mod_val + (dp[0][1][0] + dp[0][1][1] + dp[0][1][2]) % mod_val) % mod_val;
        return res;
    }
};

int main() {
    Solution s;
    cout << s.checkRecord(100000) << endl;;
    return 0;
}