#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution {
// public:
//     vector<int> singleNumber(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         for (auto a:nums) {
//             mp[a] += 1;
//         }
//         vector<int> result;
//         for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
//             if ((*iter).second == 1) {
//                 result.push_back((*iter).first);
//             } 
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        for (auto a:nums) {
            num ^= a;
        }

        int one = 0, two = 0;
        num = num & (~(num - 1)); // the rightest one bit

        for (auto a:nums) {
            if (num & a) {
                one ^= a;
            }
            else {
                two ^= a;
            }
        }

        return {one, two};
    }
};

int main() {
    Solution s;
    vector<int> nums({1,2,1,3,2,5});
    vector<int> result = s.singleNumber(nums);

    for (auto a:result) {
        cout << a << endl;
    }
    return 0;
}