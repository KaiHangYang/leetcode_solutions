#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Solution {
    vector<bool> flipped_array;
    int total_size;
    int cur_size;
    default_random_engine generator;
    int n_rows;
    int n_cols;

public:
    Solution(int n_rows, int n_cols) {
        this->n_rows = n_rows;
        this->n_cols = n_cols;
        total_size = n_rows * n_cols;
        cur_size = total_size;
        flipped_array = vector<bool>(total_size, false);
    }
    
    vector<int> flip() {
        uniform_int_distribution<int> rdm(0, cur_size-1);
        int flip_pos = rdm(generator);

        int count = 0;
        int result = 0;
        for (int i = 0; i < flipped_array.size(); ++i) {
            if (!flipped_array[i]) {
                if (count == flip_pos) {
                    flipped_array[i] = true;
                    result = i;
                    --cur_size;
                    break;
                }
                count++;
            }
        }

        return vector<int>({result / this->n_cols, result % this->n_cols});
    }
    
    void reset() {
        cur_size = total_size;
        flipped_array = vector<bool>(total_size, false);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj.flip();
 * obj.reset();
 */


int main() {
    
    return 0;
}
