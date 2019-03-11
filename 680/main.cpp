#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int N = s.size();

        int start = 0;
        int end = N-1;
        bool is_deleted = false;

        pair<int, int> another(-1, -1);

        while (start < end) {

            if (s[start] == s[end]) {
                ++start;
                --end;
            }
            else if (!is_deleted) {
                is_deleted = true;
                if (end - start == 1) {
                    return true;
                }
                else if (s[start+1] == s[end] && s[start] == s[end-1]) {
                    // chose only one to delete
                    another.first = start+1;
                    another.second = end-2;
                    ++start;
                }
                else if (s[start+1] == s[end]) {
                    ++start;
                }
                else if (s[start] == s[end-1]) {
                    --end;
                }
                else {
                    return false;
                }

                ++start;
                --end;
            }
            else if (another.first != -1 && another.second != -1) {
                start = another.first;
                end = another.second;
                another.first = -1;
                another.second = -1;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution s;
    cout << boolalpha << s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");

    return 0;
}
