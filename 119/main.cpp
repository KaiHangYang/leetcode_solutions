#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev_row(1, 1);
        for (int i = 1; i <= rowIndex; ++i) {
            vector<int> cur_row(i+1, 1);
            for (int j = 1; j < cur_row.size()-1; ++j) {
                cur_row[j] = prev_row[j-1] + prev_row[j];
            }
            prev_row = cur_row;
        }
        return prev_row;
    }
};

int main() {
    Solution s;
    vector<int> result = s.getRow(5);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
