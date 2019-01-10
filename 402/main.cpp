#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 贪心，每次选择右边最小的数
// Other poeple's implementation
class Solution {
public:
string removeKdigits(string num, int k) {
       string ans = "";                                         // treat ans as a stack in below for loop
       
       for (char c : num) {
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();                                  // make sure digits in ans are in ascending order
               k--;                                             // remove one char
           }
           
           if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0'
       }
       
       while (ans.length() && k--) { ans.pop_back(); }          // make sure remove k digits in total
       
       return ans.empty() ? "0" : ans;
}
};

//class Solution {
//public:

    //bool get_min(vector<pair<int, bool>> & num_digital, int start, int end, int & min_val, int & min_index) {
        //min_index = -1;
        //min_val = INT_MAX;

        //for (int i = start; i <= end; ++i) {
            //if (!num_digital[i].second && num_digital[i].first < min_val) {
                //min_val = num_digital[i].first;
                //min_index = i;
            //}
        //}

        //if (min_index == -1) {
            //return false;
        //}
        //else {
            //num_digital[min_index].second = true;
            //return true;
        //}
    //}

    //string removeKdigits(string num, int k) {
        //vector<pair<int, bool>> num_digital;
        //for (int i = 0; i < num.length(); ++i) {
            //num_digital.push_back(pair<int, bool>(num[i] - '0', false));
        //}

        //int total_len = num_digital.size() - k;

        //vector<pair<int, int>> result;
        //for (int i = 0; i < total_len; ++i) {
            //int start, end;
            //int cur_pos = result.size() - 1;
            //if (result.size() == 0) {
                //start = 0;
                //cur_pos = -1;
            //}
            //else {
                //start = result[cur_pos].second+1;
            //}
            //end = num_digital.size() - 1;

            //int cur_min, cur_index;
            //while (!get_min(num_digital, start, end, cur_min, cur_index)) {
                //// if get_min return False, there is no usable digital in [start, end]
                //cur_pos -= 1;
                //end = start - 1;
                //start = cur_pos < 0?0:result[cur_pos].second;
            //}
            //std::cout << "test" << std::endl;
            //result.insert(result.begin() + cur_pos + 1, pair<int, int>(cur_min, cur_index));
        //}

        //bool is_lead = true;
        //string result_str = "";
 
        //for (int i=0; i < result.size(); ++i) {
            //if (is_lead && result[i].first == 0) {
                //continue;
            //}
            //else {
                //is_lead = false;
                //result_str = result_str + to_string(result[i].first);
            //}
        //}

        //if (result_str == "") {
            //result_str = "0";
        //}

        //return result_str;
    //}
//};

int main() {
    Solution s;
    std::cout << s.removeKdigits("1432219", 3);
    return 0;
}
