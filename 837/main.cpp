#include <iostream>
#include <vector>

using namespace std;
//https://leetcode.com/problems/new-21-game/discuss/300685/C%2B%2B-DP-O(K)-time-and-space
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1.0;
        }
        float total = 0.0;
        vector<double> dp(K);
        for (int i = 0; i < K; ++i) {
            if (i < W) {
                dp[i] = (total + min(N-K+1, W-i)) / W;
            }
            else {
                dp[i] = total / W;
                total -= dp[i-W];
            }
            total += dp[i];
        }
        return dp[K-1];
    }
};

int main() {

    return 0;
}