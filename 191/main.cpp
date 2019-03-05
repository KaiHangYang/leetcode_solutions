#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n > 0) {
            if (n % 2 == 1) {
                ++sum;
            }
            n = n / 2;
        }

        return sum;
    }
};

int main() {

    Solution s;

    cout << s.hammingWeight(2);
    return 0;
}
