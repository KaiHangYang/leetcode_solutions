#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(const vector<int> &all_elms, vector<int> &v, vector<vector<int>> & results, int start, int k, int sum, int target) {
        if (sum == target) {
            if (v.size() == k) {
                results.push_back(v);
            }
            return;
        }

        for (int i = start; i < all_elms.size(); ++i) {
            if (sum+all_elms[i] <= target && v.size() < k) {
                v.push_back(all_elms[i]);
                dfs(all_elms, v, results, i+1, k, sum+all_elms[i], target);
                v.pop_back();
            }
            else {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> all_elms({1, 2, 3, 4, 5, 6, 7, 8, 9});
        vector<int> v;
        dfs(all_elms, v, results, 0, k, 0, n);

        return results;
    }
};


int main() {
    Solution s;
    vector<vector<int>> result = s.combinationSum3(3, 7);

    for (int i=0; i < result.size(); ++i) {
        for (int j=0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}
