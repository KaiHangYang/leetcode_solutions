#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    map<int, double> dp;
    
public:
    double soupServings(int N) {
        return N >= 5000?1.0:f(N, N);
    }

    double f(int A, int B) {
        if (A <= 0 && B > 0) return 1.0;
        if (A <= 0 && B <= 0) return 0.5;
        if (A > 0 && B <= 0) return 0;

        int key = A << 16 | B;
        if (!dp.count(key)) {
            dp[key] = 0.25 * (f(A-100, B) + f(A-75, B-25) + f(A-50, B-50) + f(A-25, B-75));
        }

        return dp[key];
    }
};

int main() {
    Solution s;
    cout << s.soupServings(3000);
    return 0;
}
