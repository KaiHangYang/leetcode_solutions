#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result(2, 0);
        vector<bool> exist_array(nums.size(), false);
        for (int c:nums) {
            if (exist_array[c-1]) {
                result[0] = c;
            }
            else {
                exist_array[c-1] = true;
            }
        }

        for (int i = 0; i < exist_array.size(); ++i) {
            if (!exist_array[i]) {
                result[1] = i+1;
                break;
            }
        }
        return result;
    }
};

int main () {
    Solution s;

    vector<int> nums = {3,2,3,4,6,5};
    vector<int> results = s.findErrorNums(nums);
    for (int i:results) {
        cout << i << " ";
    }
    cout << endl;
};
