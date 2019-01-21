#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string filtered_str = "";

        for (char ch:s) {
            if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
                filtered_str += ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                filtered_str += ch - 'A' + 'a';
            }
        }

        int n_str = filtered_str.length();

        for (int i = 0; i < n_str / 2; ++i) {
            if (filtered_str[i] != filtered_str[n_str-1-i]) {
                return false;
            }
        }

        return true;

    }
};

int main() {

    Solution s;
    std::cout << boolalpha << s.isPalindrome("race a car");

    return 0;
}
