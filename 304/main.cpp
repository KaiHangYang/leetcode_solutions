#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NumMatrix {
    vector<vector<int>> range_sum;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int n_rows = matrix.size();
        if (n_rows == 0) {
            return;
        }
        int n_cols = matrix[0].size();

        range_sum = vector<vector<int>>(n_rows, vector<int>(n_cols, 0));

        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                if (i - 1 >=0 && j - 1 >= 0) {
                    range_sum[i][j] = range_sum[i-1][j] + range_sum[i][j-1] - range_sum[i-1][j-1] + matrix[i][j];
                }
                else if (i - 1 >= 0) {
                    range_sum[i][j] = range_sum[i-1][j] + matrix[i][j];
                }
                else if (j - 1 >= 0) {
                    range_sum[i][j] = range_sum[i][j-1] + matrix[i][j];
                }
                else {
                    range_sum[i][j] = matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (range_sum.empty()) {
            return 0;
        }

        int sum = 0;
        if (col1 - 1 >= 0 && row1 - 1 >=0) {
            sum = range_sum[row2][col2] - range_sum[row2][col1-1] - range_sum[row1-1][col2] + range_sum[row1-1][col1-1];
        }
        else if (col1 - 1 >= 0) {
            sum = range_sum[row2][col2] - range_sum[row2][col1-1];
        }
        else if (row1 - 1 >= 0) {
            sum = range_sum[row2][col2] - range_sum[row1-1][col2];
        }
        else {
            sum = range_sum[row2][col2];
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main() {

    return 0;
}
