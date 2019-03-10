#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; ++i) {
            index[A[i]] = i;
        }

        unordered_map<int, int> dp;
        int ans = 0;
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    dp[(j << 16) + k] = dp[(i << 16) + j] + 1;
                    ans = max(dp[(j << 16) + k] + 2, ans);
                }
            }

        }
        return ans >= 3? ans:0;
    }
};

int main() {
    Solution s;
    vector<int> arr({1,3,7,11,12,14,18});
    cout << s.lenLongestFibSubseq(arr) << endl;
    return 0;
}
