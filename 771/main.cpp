#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        vector<bool> lower_arr(26, false);
        vector<bool> upper_arr(26, false);
        int cnt = 0;

        for (char c:J) {
            if (c >= 'A' && c <= 'Z') {
                upper_arr[c - 'A'] = true;
            }
            else {
                lower_arr[c - 'a'] = true;
            }
        }

        for (char c:S) {
            if (c >= 'A' && c <= 'Z' && upper_arr[c - 'A']) {
                ++cnt;
            }
            else if (c >= 'a' && c <= 'z' && lower_arr[c - 'a']) {
                ++cnt;
            }
        }

        return cnt;
    }
};

int main() {

    return 0;
}
