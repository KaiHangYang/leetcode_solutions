#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) {
            return false;
        }

        string start_RL, end_RL;
        vector<int> start_X;
        vector<int> end_X;

        int n_sx = 0;
        int n_ex = 0;

        int total_sx = 0;
        int total_ex = 0;
        for (int i = 0; i < start.length(); ++i) {
            if (start[i] == 'X') {
                n_sx += 1;
                total_sx += 1;
            }
            else {
                start_X.push_back(n_sx);
                start_RL += start[i];
                n_sx = 0;
            }

            if (end[i] == 'X') {
                n_ex += 1;
                total_ex += 1;
            }
            else {
                end_X.push_back(n_ex);
                end_RL += end[i];
                n_ex = 0;
            }
        }

        start_X.push_back(n_sx);
        end_X.push_back(n_ex);

        if (total_sx != total_ex || start_RL != end_RL) {
            return false;
        }

        for (int i = 0; i < start_X.size()-1; ++i) {
            if (start_X[i] == end_X[i]) {
                continue;
            }
            else {
                if (start_X[i] > end_X[i]) {
                    if (start_RL[i] == 'L') {
                        start_X[i+1] += start_X[i] - end_X[i];
                        start_X[i] = end_X[i];
                    }
                    else {
                        return false;
                    }
                }
                else {
                    // start_X[i] < end_X[i]
                    if (start_RL[i] == 'R') {
                        start_X[i+1] -= end_X[i] - start_X[i];
                        start_X[i] = end_X[i];
                    }
                    else {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    std::cout << s.canTransform("XXRXXLXXXX", "XXXXRXXLXX") << std::endl;
    return 0;
}
