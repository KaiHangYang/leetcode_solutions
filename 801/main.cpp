#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int N = A.size();
        if (N == 0 || N == 1) {
            return 0;
        }
        // 0 means don't swap current index, 1 means swap.
        vector<vector<int>> dp(N, vector<int>(2, 0));
        dp[0][1] = 1;

        for (int i = 1; i < N; ++i) {
            int val_0;
            int val_1;
            if (A[i] <= A[i-1] || B[i] <= B[i-1]) {
                val_0 = dp[i-1][1];
            }
            else if (A[i] > B[i-1] && B[i] > A[i-1]) {
                val_0 = min(dp[i-1][0], dp[i-1][1]);
            }
            else {
                val_0 = dp[i-1][0];
            }

            if (A[i] <= B[i-1] || B[i] <= A[i-1]) {
                val_1 = dp[i-1][1];
            }
            else if (A[i] > A[i-1] && B[i] > B[i-1]) {
                val_1 = min(dp[i-1][0], dp[i-1][1]);
            }
            else {
                val_1 = dp[i-1][0];
            }

            dp[i][0] = val_0;
            dp[i][1] = val_1 + 1;
        }

        return min(dp[N-1][0], dp[N-1][1]);
    }
};

int main() {
    Solution s;
    vector<int> A({0, 3, 5, 8, 9});
    vector<int> B({2, 1, 4, 6, 9});
    cout << s.minSwap(A, B);

    return 0;
}
