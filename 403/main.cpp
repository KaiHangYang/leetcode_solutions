#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n_stones = stones.size();
        vector<set<int>> dp(n_stones, set<int>());
        vector<int> dp_max(n_stones, 0);

        if (stones[0] != 0 || stones[1] != 1) {
            return false;
        }

        dp[1].insert(1);
        dp_max[1] = 2;

        for (int i = 2; i < n_stones; ++i) {
            for (int j = i-1; j >= 0; --j) {
                int cur_gap = stones[i] - stones[j];
                if (cur_gap > dp_max[j]) {
                    continue;
                }
                else {
                    for (int k:dp[j]) {
                        if (cur_gap == k || cur_gap == k-1 || cur_gap == k+1) {
                            dp[i].insert(cur_gap);
                            dp_max[i] = max(dp_max[i], cur_gap+1);
                        }
                    }
                }
            }
        }

        return !dp[n_stones - 1].empty();
    }
};

int main() {
    Solution s;

    vector<int> inputs({0,1,2,3,4,8,9,11});
    std::cout << boolalpha << s.canCross(inputs) << endl;
    
    return 0;
}
