#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// My solution
//class Solution {
//public:
    //int minPathSum(vector<vector<int>>& grid) {
        //int n_row = grid.size();
        //int n_col = grid[0].size();

        //vector<vector<int>> dp(n_row, vector<int>(n_col, -1));
        //// The known value
        //dp[0][0] = grid[0][0];
        //for (int i = 1; i < n_col; ++i) {
            //dp[0][i] = grid[0][i] + dp[0][i-1];
        //}
        //for (int i = 1; i < n_row; ++i) {
            //dp[i][0] = grid[i][0] + dp[i-1][0];
        //}

        //int square_size = min(n_row, n_col);

        //for (int i = 1; i < square_size; ++i) {
            //for (int j = 1; j < i; ++j) {
                //dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                //dp[j][i] = grid[j][i] + min(dp[j-1][i], dp[j][i-1]);
            //}

            //dp[i][i] = grid[i][i] + min(dp[i-1][i], dp[i][i-1]);
        //}

        //if (n_col > n_row) {
            //for (int i = square_size; i < n_col; ++i) {
                //for (int j = 1; j < n_row; ++j) {
                    //dp[j][i] = grid[j][i] + min(dp[j-1][i], dp[j][i-1]);
                //}
            //}
        //}
        //else if (n_col < n_row) {
            //for (int i = square_size; i < n_row; ++i) {
                //for (int j = 1; j < n_col; ++j) {
                    //dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                //}
            //}
        //}

        //return dp[n_row-1][n_col-1];
    //}
//};
//

// More simple implementation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n_rows = grid.size();
        int n_cols = grid[0].size();

        for (int i = 1; i < n_cols; ++i) {
            grid[0][i] += grid[0][i-1];
        }
        for (int i = 1; i < n_rows; ++i) {
            grid[i][0] += grid[i-1][0];
        }

        for (int i = 1; i < n_rows; ++i) {
            for (int j = 1; j < n_cols; ++j) {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[n_rows-1][n_cols-1];
    }
};

int main() {


    return 0;
}
