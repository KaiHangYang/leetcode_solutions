#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // use bottom-up method
        // F(S) = min (F(which last one coin) + 1)
        const int MAX_VAL = amount + 1;
        vector<int> dp(amount+1, MAX_VAL);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c:coins) {
                if (c <= i) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return dp[amount] >= MAX_VAL?-1:dp[amount];
    }
};

int main() {
    Solution s;
    vector<int> arr({1, 2, 5});
    cout << s.coinChange(arr, 11);

    return 0;
}
