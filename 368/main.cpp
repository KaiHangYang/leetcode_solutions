#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**** 暴力解法 使用dfs *****/
//class Solution {
//public:
    //bool check(const vector<int> &v, int num) {
        //// only need to check the last one, becase the sort and % a bigger number can be diviced then the smaller ones can also be divided.
        //if (num % v[v.size()-1] == 0) {
            //return true;
        //}
        //else {
            //return false;
        //}
    //}

    //bool is_in(const vector<int> &v, int num) {
        //for (int elm:v) {
            //if (elm == num) {
                //return true;
            //}
        //}
        //return false;
    //}

    //void dfs(const vector<int> &nums, vector<int> & v, vector<int> & results, int start) {
        //if (start == nums.size()) {
            //// at the end
            //if (v.size() > results.size()) {
                //// get the longest
                //results = v;
            //}
            //return;
        //}

        //for (int i = start; i < nums.size(); ++i) {
            //if (is_in(results, nums[i])) {
                //continue;
            //}

            //if (v.size() == 0) {
                //v.push_back(nums[i]);
                //dfs(nums, v, results, i+1);
                //v.pop_back();
            //}
            //else {
                //if (check(v, nums[i])) {
                    //v.push_back(nums[i]);
                    //dfs(nums, v, results, i+1);
                    //v.pop_back();
                //}
            //}
        //}

        //if (v.size() > results.size()) {
            //results = v;
        //}
    //}
    //vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        
        //vector<int> results;
        //vector<int> v;
        //dfs(nums, v, results, 0);
        //return results;
    //}
//};
/*******************/

/******* DP ********/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> T(nums.size(), 0);
        vector<int> parents(nums.size(), 0);
        int m = 0;
        int mi = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] % nums[i] == 0 && T[i] < 1 + T[j]) {
                    T[i] = 1 + T[j];
                    parents[i] = j;
                    if (T[i] > m) {
                        m = T[i];
                        mi = i;
                    }
                }
            }
        }
        vector<int> ret;

        for (int i = 0; i < m; ++i) {
            ret.push_back(nums[mi]);
            mi = parents[mi];
        }

        return ret;
    }
};

int main () {
    vector<int> input({1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824});
    Solution s;
    vector<int> results = s.largestDivisibleSubset(input);
    for (int elm:results) {
        std::cout << elm << " ";
    }
    return 0;
}
