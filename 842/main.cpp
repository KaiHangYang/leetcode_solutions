#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:

    void dfs(const vector<int> & s_digital, vector<int> &v, vector<int> &result, int start, int prev_len) {
        if (start == s_digital.size()) {
            if (v.size() >= 3) {
                result = v;
            }
            return;
        }
        
        if (v.size() <= 2) {
            // if the array length hasn't reach 2
            prev_len = 1;
        }

        for (int cur_len = prev_len; cur_len <= s_digital.size() - start; ++cur_len) {
            if (result.size() != 0) {
                return;
            }

            long long cur_num;
            if (!get_digital(s_digital, start, cur_len, cur_num)) {
                // invalid number
                return;
            }

            int last_length = s_digital.size() - start - cur_len;

            if (v.size() < 2) {
                v.push_back(cur_num);
                dfs(s_digital, v, result, start + cur_len, cur_len);
                v.pop_back();
            }
            else if (cur_num == v[v.size() - 1] + v[v.size() - 2]) {
                if  (last_length == 0 || last_length >= cur_len) {
                    v.push_back(cur_num);
                    dfs(s_digital, v, result, start + cur_len, cur_len);
                    v.pop_back();
                }
                else {
                    return;
                }
            }
        }
    }

    vector<int> splitIntoFibonacci(string S) {
        vector<int> s_digital(S.length(), 0);
        for (int i = 0; i < S.length(); ++i) {
            s_digital[i] = S[i] - '0';
        }
        vector<int> v;
        vector<int> result;
        dfs(s_digital, v, result, 0, 1);
        return result;
    }

    bool get_digital(const vector<int> & s_digital, int pos, int len, long long & result) {
        result = 0;
        // The lead character can't be 0
        if (s_digital[pos] == 0 && len > 1) {
            return false;
        }

        for (int i = 0; i < len; ++i) {
            result += s_digital[pos+i] * pow(10, len-i-1);
            if (result > INT_MAX) {
                result = 0;
                return false;
            }
        }
        return true;
    }
};

int main() {
    string input("26680333094522122405874374286875202793245124106023438638154307674529081118998476463547521258509819378850611547943714168887018710248914570324093142954155261448272417373604331561828074147927642892139798");
    Solution s;
    vector<int> result = s.splitIntoFibonacci(input);
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }

    std::cout << std::endl;
    
    return 0;
}
