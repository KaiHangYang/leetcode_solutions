#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> result;
        vector<int> patten_b(26, 0);
        for (auto str:B) {
            vector<int> tmp(26, 0);
            for (auto c:str) {
                tmp[c-'a']++;
            }

            for (int i = 0; i < 26; ++i) {
                patten_b[i] = max(patten_b[i], tmp[i]);
            }
        }
        for (auto str:A) {
            vector<int> patten(26, 0);
            for (auto c:str) {
                patten[c - 'a'] ++;
            }
            bool is_valid = true;
            for (int i = 0; i < 26; ++i) {
                if (patten[i] < patten_b[i]) {
                    is_valid = false;
                }
            }
            if (is_valid) {
                result.push_back(str);
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<string> A({"amazon","apple","facebook","google","leetcode"});
    vector<string> B({"l","e"});
    vector<string> result = s.wordSubsets(A, B);
    for (auto t:result) {
        cout << t << endl;
    }
    return 0;
}