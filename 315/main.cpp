#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdlib.h>

using namespace std;
// The merge-sort thought
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76607/C%2B%2B-O(nlogn)-Time-O(n)-Space-MergeSort-Solution-with-Detail-Explanation
class Solution {
public:
    void merge_countSmaller(vector<int>& indices, int first, int last, vector<int>& results, const vector<int>& nums) {
        // [first, last)
        int count = last - first;
        if (count > 1) {
            int step = count / 2;
            int mid = first + step;
            merge_countSmaller(indices, first, mid, results, nums);
            merge_countSmaller(indices, mid, last, results, nums);

            vector<int> tmp_indices;
            int idx1 = first;
            int idx2 = mid;

            int semicount = 0;

            while (idx1 < mid || idx2 < last) {
                if ((idx2 == last) || (idx1 < mid) && (nums[indices[idx1]] <= nums[indices[idx2]])) {
                    // put idx1
                    tmp_indices.push_back(indices[idx1]);
                    results[indices[idx1]] += semicount;
                    ++idx1;
                }
                else {
                    // put idx2
                    tmp_indices.push_back(indices[idx2]);
                    ++semicount;
                    ++idx2;
                }
            }
            move(tmp_indices.begin(), tmp_indices.end(), indices.begin() + first);
        }

    }
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> indices(n, 0);
        iota(indices.begin(), indices.end(), 0);
        vector<int> results(n, 0);

        merge_countSmaller(indices, 0, n, results, nums);
        return results;
    }

};

int main () {
    
    return 0;
}
