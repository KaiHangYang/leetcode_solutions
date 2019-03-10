#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

/*** Avoid using map ***/
class Solution {
    int n;
    vector<int> arr;
    double dp[200][200];

    vector<int> sum_arr;
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        this->n = A.size();
        this->arr = A;
        this->sum_arr = A;
        fill(this->dp[0], this->dp[0] + 40000, 0);

        for (int i = 1; i < this->n; ++i) {
            this->sum_arr[i] += this->sum_arr[i-1];
        }

        return dfs(0, K);
    }

    double dfs(int l, int K) {

        if (dp[l][K] > 0) return dp[l][K];

        if (l == n - 1) {
            dp[l][K] = this->arr[l];
            return dp[l][K];
        }

        if (K == 1) {
            double cur_val = l > 0?this->sum_arr[this->n-1] - this->sum_arr[l-1]:this->sum_arr[this->n-1];
            dp[l][K] = cur_val / (n - l);
            return dp[l][K];
        }


        double max_val = 0;
        double cur_val;
        double cur_sum;

        for (int i = n - 1; i >= l; --i) {
            cur_sum = l > 0?this->sum_arr[i] - this->sum_arr[l-1]:this->sum_arr[i];
            cur_val = cur_sum / (i - l + 1) + dfs(i+1, K-1);
            if (cur_val > max_val) {
                max_val = cur_val;
            }
        }

        dp[l][K] = max_val;
        return dp[l][K];
    }
};

int main() {
    Solution s;

    vector<int> A({9,1,2,3,9});
    cout << s.largestSumOfAverages(A, 3);

    return 0;
}
