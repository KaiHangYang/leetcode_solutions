#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    stack<pair<int,int>> arr;

public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty() || (preorder.size() == 1 && preorder[0] == '#')) {
            return true;
        }
        if (preorder.size() < 3) {
            return false;
        }
        int num = 0;
        bool is_term = false;
        bool first_num = true;
        for (int i = 0; i <= preorder.size(); ++i) {
            if (i == preorder.size() || preorder[i] == ',') {
                // meet the finish
                if (is_term) {
                    // the previous char is #
                    if (arr.empty()) {
                        return false;
                    }
                    else {
                        arr.top().second += 1;
                        while (!arr.empty() && arr.top().second >= 2) {
                            if (arr.top().second > 2) {
                                return false;
                            }
                            else {
                                arr.pop();
                                if (!arr.empty()) {
                                    arr.top().second += 1;
                                }
                            }
                        }
                    }
                }
                else {
                    if (arr.empty() && !first_num) {
                        return false;
                    }
                    arr.push(pair<int, int>(num, 0));
                    first_num = false;
                }
                num = 0;
            }
            else if (preorder[i] == '#') {
                is_term = true;
            }
            else {
                is_term = false;
                num = num * 10 + preorder[i] - '0';
            }
        }
        return arr.empty();
    }
};

int main() {
    Solution s;
    cout << boolalpha << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
    return 0;
}