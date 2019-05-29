#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n_str = ring.size();
        vector<vector<int>> letter_positions(26, vector<int>());
        for (int i = 0; i < n_str; ++i) {
            letter_positions[ring[i] - 'a'].push_back(i);
        }
        vector<pair<int, int>> dp_prev, dp_cur;
        dp_prev.push_back(pair<int,int>(0, 0));

        for (char c:key) {
            for (int i = 0; i < letter_positions[c-'a'].size(); ++i) {
                int cur_pos = letter_positions[c-'a'][i];
                int min_step = numeric_limits<int>::max();
                for (int j = 0; j < dp_prev.size(); ++j) {
                    int min_pos = min(cur_pos, dp_prev[j].first);
                    int max_pos = max(cur_pos, dp_prev[j].first);
                    min_step = min(dp_prev[j].second + min(max_pos - min_pos, min_pos + n_str - max_pos), min_step);
                }
                dp_cur.push_back(pair<int,int>(cur_pos, min_step));
            }
            dp_prev = dp_cur;
            dp_cur.clear();
        }
        int min_step = numeric_limits<int>::max();
        for (int i = 0; i < dp_prev.size(); ++i) {
            min_step = min(min_step, dp_prev[i].second);
        }
        return min_step + key.size();
    }
};

int main() {
    Solution s;
    cout << s.findRotateSteps("godding", "godding") << endl;
    return 0;
}