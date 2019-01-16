#include <iostream>
#include <vector>

using namespace std;

/***** 填充物的思想，偶数奇数 挤出去一个数 ******/
class Solution {
public:
    int search(const vector<int>& nums, int start, int end) {
        // Judge the mid number belongs to which side.
        if (end - start == 1) {
            return nums[start];
        }
        else if (end - start == 3) {
            if (nums[start] == nums[start+1]) {
                return nums[start+2];
            }
            else if (nums[start] == nums[start+2]) {
                return nums[start+1];
            }
            else {
                return nums[start];
            }
        }

        int len = (end - start) / 2;
        int mid = (end + start) / 2;

        if (len % 2 == 0) {
            if (nums[mid] == nums[mid - 1] || nums[mid] == nums[mid - 2]) {
                return search(nums, start, mid+1);
            }
            else if (nums[mid] == nums[mid + 1] || nums[mid] == nums[mid + 2]) {
                return search(nums, mid, end);
            }
            else {
                return nums[mid];
            }
        }
        else {
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) {
                return nums[mid];
            }
            else if (nums[mid] == nums[mid+1]) {
                return search(nums, start, mid);
            }
            else {
                return search(nums, mid+1, end);
            }
        }

    } 
    int singleNonDuplicate(vector<int>& nums) {
        return search(nums, 0, nums.size());
    }
};

int main() {
    vector<int> inputs({3,3,7,7,10,11,11});
    Solution s;
    std::cout << s.singleNonDuplicate(inputs) << std::endl;
    return 0;
}
