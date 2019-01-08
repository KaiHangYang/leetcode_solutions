#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L = ceil(sqrt(area));
        int W;

        for (int i = L; i <= area; ++i) {
            if (area % L == 0) {
                W = area / L;
                break;
            }
        }

        return std::vector<int>({L, W});
    }
};

int main() {
    Solution s;

    vector<int> result = s.constructRectangle(4);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }


    return 0;
}
