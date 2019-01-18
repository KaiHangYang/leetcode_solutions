#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

class Solution {
public:

    void binary_insert(vector<pair<int, int>>& window, pair<int, int> elm, int start, int end) {
        if (end - start <= 1) {

            if (end == start || window[start].first >= elm.first) {
                window.insert(window.begin() + start, elm);
            }
            else {
                window.insert(window.begin() + start + 1, elm);
            }
            return;
        }

        int mid = (start + end) / 2;
        if (elm.first >= window[mid].first) {
            binary_insert(window, elm, mid+1, end);
        }
        else {
            binary_insert(window, elm, start, mid);
        }

    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> results;
        vector<pair<int, int>> window;
        pair<int, int> median_pos;
        int pop_index = 0;
        int n_size = nums.size();

        if (k % 2 == 0) {
            median_pos.first = k / 2 - 1;
            median_pos.second = k / 2;
        }
        else {
            median_pos.first = k / 2;
            median_pos.second = median_pos.first;
        }

        window.reserve(k);
        for (int i = 0; i < k; ++i) {
            window.push_back(pair<int, int>(nums[i], i));
        }
        sort(window.begin(), window.end(), comp);

        for (int i = 0; i < n_size - k + 1; ++i) {
            results.push_back((static_cast<double>(window[median_pos.first].first) + window[median_pos.second].first) / 2.0);
            // then pop i and push i + k
            if (i + k == n_size) {
                break;
            }

            binary_insert(window, pair<int, int>(nums[i + k], i + k), 0, window.size());
            window.erase(find(window.begin(), window.end(), pair<int, int>(nums[i], i)));
        }

        return results;

    }
};

int main() {

    vector<int> inputs({-2147483648,-2147483648,2147483647,-2147483648,-2147483648,-2147483648,2147483647,2147483647,2147483647,2147483647,-2147483648,2147483647,-2147483648});
    Solution s;
    vector<double> result = s.medianSlidingWindow(inputs, 2);
    for (double d:result) {
        std::cout << d << std::endl;
    }

    return 0;
}
