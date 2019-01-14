#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int arrangeCoins(int n) {
        long long cur_total = 0;

        if (n == 0) {
            return 0;
        }
        int cur_row = 1;

        while (cur_total < n) {
            cur_total += cur_row;
            ++cur_row;
        }
        if (cur_total == n) {
            --cur_row;
        }
        else {
            cur_row -= 2;
        }

        return cur_row;
    }
};

int main() {
    Solution s;
    std::cout << s.arrangeCoins(2147483647) << std::endl;
}
