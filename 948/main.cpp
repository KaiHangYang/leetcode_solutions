#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.empty()) {
            return 0;
        }
        sort(tokens.begin(), tokens.end());
        int l = 0, r = tokens.size() - 1;

        int point = 0;
        while (l <= r) {
            if (P >= tokens[l]) {
                P -= tokens[l++];
                ++point;
            }
            else if (r - l > 1 && point > 0) {
                P += tokens[r--];
                --point;
            }
            else {
                break;
            }
        }

        return point;
    }
};

int main() {
    Solution s;
    vector<int> tokens({100,200,300,400});
    s.bagOfTokensScore(tokens, 200);

    return 0;
}
