#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/***** Wrong DP usage.....  *****/
/***** More like a expanding method ******/
//using namespace std;

//class Solution {
//public:
    //string longestPalindrome(string s) {
        //if (s == "") {
            //return "";
        //}

        //vector<pair<string, pair<int, int>>> cur_dp, tmp_dp;
        //int str_len = s.length();
        //int cur_level = 1;

        //cur_dp.reserve(str_len);
        //for (int i = 0; i < str_len; ++i) {
            //cur_dp.push_back(pair<string, pair<int, int>>(s.substr(i, 1), pair<int, int>(i, i)));
            //if (i+1 < str_len && s[i] == s[i+1]) {
                //cur_dp.push_back(pair<string, pair<int, int>>(s.substr(i, 2), pair<int, int>(i, i+1)));
            //}
        //}

        //// add the two same substr

        //while (true) {
            //tmp_dp.clear();
            
            //for (int i = 0; i < cur_dp.size(); ++i) {
                //pair<string, pair<int, int>> cur_elm = cur_dp[i];
                //int mid_head_index = cur_elm.second.first;
                //int mid_tail_index = cur_elm.second.second;

                //int head_index = mid_head_index - cur_level;
                //int tail_index = mid_tail_index + cur_level;

                //if (head_index >= 0 && tail_index < str_len && s[head_index] == s[tail_index]) {
                    //// in the string range and is palindromic
                    //cur_elm.first = s[head_index] + cur_elm.first + s[tail_index];
                    //tmp_dp.push_back(cur_elm);
                //}
            //}

            //++cur_level;

            //if (tmp_dp.empty()) {
                //break;
            //}
            //else {
                //cur_dp = tmp_dp;
            //}

        //}

        //int max_len = 0;
        //string max_str = "";

        //for (int i = 0; i < cur_dp.size(); ++i) {
            //if (cur_dp[i].first.length() > max_len) {
                //max_str = cur_dp[i].first;
                //max_len = max_str.length();
            //}
        //}

        //return max_str;
    //}
//};

/******** Simple expanding *********/
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s == "") {
            return "";
        }

        int str_len = s.length();

        string max_str = "";
        int max_len = 0;

        for (int i = 0; i < str_len; ++i) {
            vector<pair<string, pair<int, int>>> centers;
            centers.push_back(pair<string, pair<int, int>>(s.substr(i, 1), pair<int, int>(i, i)));
            
            if (i + 1 < str_len && s[i] == s[i+1]) {
                centers.push_back(pair<string, pair<int, int>>(s.substr(i, 2), pair<int, int>(i, i+1)));
            }

            for (int j = 0; j < centers.size(); ++j) {
                pair<string, pair<int, int>> cur_center = centers[j];
                int mid_head_index = cur_center.second.first;
                int mid_tail_index = cur_center.second.second;
                int cur_len = 1;

                int head_index = mid_head_index - cur_len;
                int tail_index = mid_tail_index + cur_len;

                while (head_index >= 0 && tail_index < str_len && s[head_index] == s[tail_index]) {
                    cur_center.first = s[head_index]+cur_center.first+s[tail_index];
                    ++cur_len;
                    head_index = mid_head_index - cur_len;
                    tail_index = mid_tail_index + cur_len;
                }
                
                if (cur_center.first.length() > max_len) {
                    max_str = cur_center.first;
                    max_len = max_str.length();
                }
            }
        }
        return max_str;
    }
};

int main() {
    Solution s;
    std::cout << s.longestPalindrome("babad") << std::endl;

    return 0;
}
