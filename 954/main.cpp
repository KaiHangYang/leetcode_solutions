#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> m;
        for (auto i:A) {
            m[i]++;
        }

        for (auto i:A) {
            if (m[i] <= 0) {
                continue;
            }

            int val = i < 0?i/2:i*2;
            if (m[val] <= 0) {
                return false;
            }
            else {
                m[val]--;
            }
            m[i]--;
        }
        return true;
    }
};


int main() {
    return 0;
}