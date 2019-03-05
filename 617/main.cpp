#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int str_len = s.size();
        for (int i = 0; i < str_len / 2; ++i) {
            tmp = s[i];
            s[i] = s[str_len - 1 - i];
            s[str_len - 1 - i] = tmp;
        }
    }
};

int main() {
    Solution s;
    vector<char> str({'h', 'e', 'i', 'l', 'o'});
    s.reverseString(str);

    for (int i = 0; i < str.size(); ++i) {
        std::cout << str[i] << std::endl;
    }

    return 0;
}
