#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0] = A[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + A[i][j];
                }
                else if (j == n-1) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + A[i][j];
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i-1][j+1]) + A[i][j];
                }
            }
        }

        int min_val = numeric_limits<int>::max();

        for (int i = 0; i < n; ++i) {
            if (dp[n-1][i] < min_val) {
                min_val = dp[n-1][i];
            }
        }

        return min_val;

    }
};

int main() {

    return 0;
}
