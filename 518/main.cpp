#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }

        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n, 0));

        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = dp[]
            }
        }
    }
};

int main() {

    return 0;
}
