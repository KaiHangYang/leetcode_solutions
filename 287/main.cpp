#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 首先这个数组可以看成静态链表，并且只有在有环的情况下才会出现重复节点，检测环的话使用floyd cycle detector.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if (slow == fast) {
                // if has cycle, must come here, and the begin of the cycle must have to father.
                fast = 0;
                while (fast != slow) {
                    slow = nums[slow];
                    fast = nums[fast];
                }
                
                return fast;
            }
        }
        return 0;
    }
};

int main() {
    Solution s;
    vector<int> nums({2,2,3,1,4});
    std::cout << s.findDuplicate(nums) << std::endl;

    return 0;
}
