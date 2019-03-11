#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        vector<string> s_arr(numRows, "");
        int n = 2*numRows - 2;


        for (int i = 0; i < s.size(); ++i) {
            int cur_index = i % n;
            if (cur_index >= numRows) {
                cur_index = n - cur_index;
            }
            s_arr[cur_index] += s[i];
        }

        string result = "";
        for (string& lin_s:s_arr) {
            result += lin_s;
        }

        return result;
    }
};

int main() {

    Solution s;
    cout << s.convert("PAYPALISHIRING", 4);

    return 0;
}
