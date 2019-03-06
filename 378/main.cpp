#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct COMP {
    bool operator () (const int& a, const int& b) const {
        return a < b;
    }
};

// binary search is also n^2logn
// so I use simple priority_queue version
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, COMP> q;
        int n = matrix.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                q.push(matrix[i][j]);

                if (q.size() > k) q.pop();
            }
        }

        return q.top();
    }
};

int main () {

    return 0;
}
