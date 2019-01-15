#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binary_search(const vector<int>& nums, int start, int end, int target) {
        if (start >= end) {
            return -1;
        }

        int mid = (end + start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            return binary_search(nums, mid+1, end, target);
        }
        else {
            return binary_search(nums, start, mid, target);
        }

    }
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        return binary_search(nums, start, end, target);
    }
};

int main() {
    vector<int> nums({-1,0,3,5,9,12});
    Solution s;
    cout << s.search(nums, 2);
    return 0;
}
