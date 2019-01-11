#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/******************这个问题主要是剪枝策略的问题，逆序数组要比顺序好，因为可以提前判断不合适（最大数如果加上任何数都大于边长的话一定不行）********************/
bool cmp(const int & a, const int & b) {
    return a > b;
}

class Solution {
public:
    void dfs(const vector<int> &nums, vector<bool> &visited, bool & is_found, int cur_sum, int cur_count, int target) {
        if (cur_count == 4) {
            // find the case to form a square
            is_found = true;
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {

            if (visited[i]) {
                continue;
            }

            if (cur_sum + nums[i] > target || is_found) {
                // nums are sorted
                return;
            }
            else {
                int tmp_sum = cur_sum;
                int tmp_count = cur_count;

                if (tmp_sum + nums[i] == target) {
                    tmp_count += 1;
                    tmp_sum = 0;
                }
                else {
                    tmp_sum = tmp_sum + nums[i];
                }
                visited[i] = true;
                dfs(nums, visited, is_found, tmp_sum, tmp_count, target);
                visited[i] = false;
            }
        }
    }
    bool makesquare(vector<int>& nums) {
        int total_length = 0;
        sort(nums.begin(), nums.end(), cmp);

        for (int e:nums) {
            total_length += e;
        }

        if (total_length % 4 != 0) {
            return false;
        }
        else {
            int width = total_length / 4;

            bool is_found = false;
            vector<bool> visited(nums.size(), false);
            dfs(nums, visited, is_found, 0, 0, width);
            return is_found;
        }
    }
};

int main () {
    vector<int> inputs({5,5,5,5,16,4,4,4,4,4,3,3,3,3,4});
    Solution s;
    std::cout << std::boolalpha << s.makesquare(inputs) << std::endl;
    return 0;
}
