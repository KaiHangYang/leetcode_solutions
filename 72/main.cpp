#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len_1 = word1.size();
        int len_2 = word2.size();
        vector<vector<int>> dp(len_1 + 1, vector<int>(len_2 + 1, 0));

        for (int i = 1; i <= len_1; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= len_2; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= len_1; ++i) {
            for (int j = 1; j <= len_2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }

        return dp[len_1][len_2];

    }
};


int main() {

    return 0;
}
