#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    vector<int> number_array;
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.reserve(n);
        dp.push_back(1);
        int pt_2=0, pt_3=0, pt_5=0;
        while (dp.size() < n) {
            dp.push_back(min(dp[pt_2] * 2, min(dp[pt_3] * 3, dp[pt_5] * 5)));
            if (dp.back() == dp[pt_2] * 2) ++pt_2;
            if (dp.back() == dp[pt_3] * 3) ++pt_3;
            if (dp.back() == dp[pt_5] * 5) ++pt_5;
        }
        return dp.back();
    }
};

int main() {
    Solution s;
    cout << s.nthUglyNumber(10);

    return 0;
}
