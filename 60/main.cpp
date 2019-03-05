#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k = k - 1;
        vector<int> arr(n, 1);
        for (int i = n-2; i >= 0; --i) {
            arr[i] = arr[i+1] * (n - i);
        }

        vector<char> number_arr(n, '0');
        for (int i = 0; i < n; ++i) {
            number_arr[i] += i + 1;
        }

        string result("");
        for (int i = 0; i < n; ++i) {
            if (i != n-1) {
                int cur_index = k / arr[i+1];
                result = result + number_arr[cur_index];
                k = k % arr[i+1];
                number_arr.erase(number_arr.begin() + cur_index);
            }
            else {
                result = result + number_arr[0];
            }
        }

        return result;
    }
};


int main() {
    Solution s;
    std::cout << s.getPermutation(3, 6) << std::endl;;
    return 0;
}
