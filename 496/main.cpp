#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;

        for (int n:nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }

        vector<int> result;
        result.reserve(findNums.size());

        for (int fn:findNums) {
            if (m.count(fn)) {
                result.push_back(m[fn]);
            }
            else {
                result.push_back(-1);
            }
        }

        return result;
    }
};

int main() {

    return 0;
}
