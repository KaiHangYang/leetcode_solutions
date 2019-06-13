#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (auto a:asteroids) {
            if (s.empty() || s.top() < 0 || (s.top() > 0 && a > 0)) {
                s.push(a);
            }
            else {
                // s.top() > 0 && a < 0
                bool discard = false;
                while (!s.empty() && s.top() > 0) {
                    if (s.top() + a > 0) {
                        discard = true;
                        break;
                    }
                    else if (s.top() + a == 0) {
                        discard = true;
                        s.pop();
                        break;
                    }
                    else {
                        s.pop();
                    }
                }
                if (!discard) {
                    s.push(a);
                }
            }
        }
        vector<int> result;
        while (!s.empty()) {
            result.insert(result.begin(), s.top());
            s.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> input({8, -8});
    vector<int> result = s.asteroidCollision(input);
    for (auto a:result) {
        cout << a << endl;
    }
    return 0;
}