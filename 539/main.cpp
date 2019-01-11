#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

// bucket rank
class Solution {
public:
    int str2int(const string & str) {
        return atoi(str.substr(0, 2).c_str()) * 60 + atoi(str.substr(3, 2).c_str());
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> time_point_exists(1440, false);
        vector<int> time_array;
        time_array.reserve(1441);

        for (string cur_tp:timePoints) {
            int cur_time = str2int(cur_tp);
            if (time_point_exists[cur_time]) {
                return 0;
            }
            else {
                time_point_exists[cur_time] = true;
            }
        }

        for (int i = 0; i < time_point_exists.size(); ++i) {
            if (time_point_exists[i]) {
                time_array.push_back(i);
            }
        }
        /** Pay Attention to this **/
        time_array.push_back(time_array[0] + 1440);

        int min_range = numeric_limits<int>::max();
        for (int i = 0; i < time_array.size() - 1; ++i) {
            if (min_range > time_array[i+1] - time_array[i]) {
                min_range = time_array[i+1] - time_array[i];
            }
        }

        return min_range;
    }
};
