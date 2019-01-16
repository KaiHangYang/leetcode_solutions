#include <iostream>
#include <vector>
#include <string>

// O(log(n)) binary search
// Simple problem must be carefull!!!!!!!!!!!!!
class Solution {
public:
    int search(const vector<int>& nums, int start, int end, int target) {
        if (end <= start + 1) {
            // here cause I handled the edge case first, so nums[start] must <= target and nums[end] >= target
            if (nums[start] == target) {
                return start;
            }
            else {
                return start + 1;
            }
        }

        int mid = (start + end) / 2;

        if (target < nums[mid]) {
            return search(nums, start, mid, target);
        }
        else {
            return search(nums, mid, end, target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) {
            return 0;
        }
        else if (target > nums[nums.size() - 1]) {
            return nums.size();
        }
        else {
            return search(nums, 0, nums.size(), target);
        }
    }
};

int main() {
    
    return 0;
}
