#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        int n = digits.size();
        vector<string> num2alpha(8, "");
        vector<int> cur_level(n, 0);
        vector<string> results;

        num2alpha[0] = "abc";
        num2alpha[1] = "def";
        num2alpha[2] = "ghi";
        num2alpha[3] = "jkl";
        num2alpha[4] = "mno";
        num2alpha[5] = "pqrs";
        num2alpha[6] = "tuv";
        num2alpha[7] = "wxyz";

        while (true) {
            string tmp("");
            for (int i = 0; i < n; ++i) {
                int cur_digit = digits[i] - '2';
                tmp += num2alpha[cur_digit][cur_level[i]];
            }
            results.push_back(tmp);

            bool is_increased = false;
            for (int i = n - 1; i >= 0; --i) {
                int cur_digit = digits[i] - '2';
                if (cur_level[i] < num2alpha[cur_digit].size() - 1) {
                    ++cur_level[i];
                    is_increased = true;
                    break;
                }
                else {
                    cur_level[i] = 0;
                } 
            }

            if (!is_increased) {
                break;
            }
        }

        return results;
    }
};

int main() {
    Solution s;
    vector<string> results = s.letterCombinations("23");

    for (string s:results) {
        cout << s << endl;
    }

    return 0;
}
