#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    // DP problem
    int partitionDisjoint(vector<int>& A) {
        int n_size = A.size();
        vector<int> backward(n_size, numeric_limits<int>::max());

        for (int i = n_size - 2; i >= 0; --i) {
            backward[i] = min(backward[i+1], A[i+1]);
        }

        int cur_max = 0;
        for (int i = 0; i < n_size; ++i) {
            cur_max = max(A[i], cur_max);
            if (cur_max <= backward[i]) {
                return i+1;
            }
        }

        return n_size;
    }
};

int main() {

    vector<int> inputs({1,0,0,0,0});
    Solution s;
    std::cout << s.partitionDisjoint(inputs);
    return 0;
}
