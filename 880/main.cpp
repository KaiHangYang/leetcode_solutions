#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    string decodeAtIndex(string S, int K) {
        int size_s = S.size();
        int size_raw = 0;

        for (char c:S) {
            if (isalpha(c)) {
                ++size_raw;
            }
            else {
                size_raw *= c - '0';
            }
        }

        for (int i = size_s - 1; i >= 0; --i) {

            K = K % size_raw;

            if (K == 0 && isalpha(S[i])) {
                return S.substr(i, 1);
            }

            if (isalpha(S[i])) {
                --size_raw;
            }
            else {
                size_raw /= S[i] - '0';
            }
        }
    }
};

int main() {
    Solution s;
    s.decodeAtIndex("leet2code3", 10);
    return 0;
}
