#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, tails;
        for (int& n:nums) {
            cnt[n]++;
        }

        for (int& n:nums) {
            if (cnt[n] == 0) {
                continue;
            }
            cnt[n]--;

            if (tails[n-1]) {
                tails[n-1]--;
                tails[n]++;
            }
            else if (cnt[n+1] && cnt[n+2]) {
                // A new one
                cnt[n+1]--;
                cnt[n+2]--;
                tails[n+2]++;
            }
            else {
                return false;
            }
        }

        return true;
    }
};

int main() {

    return 0;
}
