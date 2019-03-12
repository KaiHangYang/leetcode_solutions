#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int n = nums.size();
        int sum = 0;
        for (int& a:nums) {
            sum += a;
        }

        if (sum % 2) {
            return false;
        }

        int W = sum / 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(W+1, false));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; ++i) {
            for (int target=1; target <= W; ++target) {
                if (nums[i-1] > target) {
                    dp[i][target] = dp[i-1][target];
                }
                else {
                    dp[i][target] = dp[i-1][target] || dp[i-1][target-nums[i-1]];
                }
            }
        }

        return dp[n][W];
    }
};

int main() {
    return 0;
}
