#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rand7() {
    return 0;
}

class Solution {
public:
    int randn(int n) {
        int k = rand7();
        if (k <= n) return k;
        else return randn(n);
    }

    int rand10() {
        if (randn(6) > 3) {
            return randn(5);
        }
        else {
            return 5+randn(5);
        }
    }
};

int main() {

    return 0;
}
