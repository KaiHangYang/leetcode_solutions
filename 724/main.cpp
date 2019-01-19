#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) {
            return -1;
        }

        int n_size = nums.size();

        vector<int> left_sum(n_size, 0);
        vector<int> right_sum(n_size, 0);

        left_sum[0] = nums[0];
        right_sum[n_size-1] = nums[n_size-1];

        for (int i = 1; i < n_size; ++i) {
            left_sum[i] = left_sum[i-1] + nums[i];
            right_sum[n_size - i - 1] = right_sum[n_size - i] + nums[n_size - i - 1];
        }

        int pivot = -1;
        for (int i = 0; i < n_size; ++i) {
            if (left_sum[i] == right_sum[i]) {
                pivot = i;
                break;
            }
        }

        return pivot;

    }
};

int main() {
    Solution s;

    vector<int> nums({-1,-1,0,0,-1,-1});
    std::cout << s.pivotIndex(nums) << std::endl;

    return 0;
}
