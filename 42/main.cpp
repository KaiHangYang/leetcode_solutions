#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n_size = height.size();
        if (n_size == 0) {
            return 0;
        }
        int max_index = -1;
        int max_height = 0;
        int total_water = 0;

        for (int i = 0; i < n_size; ++i) {
            if (max_height < height[i]) {
                max_height = height[i];
                max_index = i;
            }
        }

        int cur_height = 0;
        for (int i = 0; i < max_index; ++i) {
            if (height[i] < cur_height) {
                total_water += cur_height - height[i];
            }
            else {
                cur_height = height[i];
            }
        }

        cur_height = 0;

        for (int i = n_size - 1; i > max_index; --i) {
            if (height[i] < cur_height) {
                total_water += cur_height - height[i];
            }
            else {
                cur_height = height[i];
            }
        }

        return total_water;
    }
};

int main() {
    Solution s;

    vector<int> heights({5,2,1,2,1,5});
    std::cout << s.trap(heights) << std::endl;

    return 0;
}
