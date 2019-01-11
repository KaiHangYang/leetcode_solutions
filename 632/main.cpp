#include <iostream>
#include <vector>
#include <queue>
#include <limits>

// https://leetcode.com/problems/smallest-range/discuss/180839/c%2B%2B-99-priority-queue.-easy-to-explain-and-impl-in-10mins.-cheers!
using namespace std;

struct Item {
    int val;
    int r;
    int c;

    Item(int val, int r, int c): val(val), r(r), c(c) {}
};

struct Comp {
    bool operator() (const Item& it1, const Item& it2) {
        return it1.val > it2.val;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Item, vector<Item>, Comp> pq;
        int n = nums.size();
        int high = numeric_limits<int>::min();
        for (int i = 0; i < n; ++i) {
            pq.push(Item(Item(nums[i][0], i, 0)));
            high = max(nums[i][0], high);
        }
        int low = pq.top().val;

        vector<int> res({low, high});

        while (pq.size() == n) {
            auto it = pq.top();
            pq.pop();

            if (it.c + 1 < nums[it.r].size()) {
                pq.push(Item(nums[it.r][it.c+1], it.r, it.c+1));
                high = max(high, nums[it.r][it.c + 1]);
                low = pq.top().val;

                if (high - low < res[1] - res[0]) {
                    res[1] = high;
                    res[0] = low;
                }
            }
        }
        return res;
    }
};

int main () {
    Solution s;
    vector<vector<int>> inputs({
            {1, 3, 7, 8},
            {10, 394, 555},
            });

    vector<int> res = s.smallestRange(inputs);
    std::cout << res[0] << " " << res[1] << std::endl;
    return 0;
}
