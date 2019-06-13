#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // O(n^2)
    // int subarraySum(vector<int>& nums, int k) {
    //     vector<long long> sum_arr(nums.size()+1, 0);
    //     for (int i = 0; i < nums.size(); ++i) {
    //         sum_arr[i+1] = nums[i] + sum_arr[i];
    //     }
    //     int cnt = 0;
    //     for (int start = 0; start < nums.size(); ++start) {
    //         for (int end = start+1; end <= nums.size(); ++end) {
    //             if (sum_arr[end] - sum_arr[start] == k) {
    //                 ++cnt;
    //             }
    //         }
    //     }
    //     return cnt;
    // }
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;
        long long total = 0;
        int cnt = 0;
        for (auto n:nums) {
            mp[total]++;
            total += n;
            cnt += mp[total - k];
        }
        return cnt;
    }
};

int main() {
    Solution s;
    vector<int> arr({-3, -4, -3, 0, 3, 3, 3});
    cout << s.subarraySum(arr, 0) << endl;
    return 0;
}