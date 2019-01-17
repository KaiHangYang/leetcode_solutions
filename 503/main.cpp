#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> results(nums.size(), -1);
        stack<int> s;

        // first cycle to find all OK values
        for (int i=0; i < nums.size(); ++i) {
            while (s.size() && nums[s.top()] < nums[i]) {
                results[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }

        for (int n:nums) {
            while (s.size() && nums[s.top()] < n) {
                results[s.top()] = n;
                s.pop();
            }
        }

        return results;
    }
};

int main() {

    return 0;
}
