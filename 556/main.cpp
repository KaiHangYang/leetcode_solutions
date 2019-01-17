#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool comp(const int& a, const int& b) {
    return a > b;
}

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> exact_big(10, -1);
        vector<int> number_array;
        vector<int> result_array;
        number_array.reserve(20);

        while (n != 0) {
            number_array.push_back(n % 10);
            n /= 10;
        }
        
        int from_index;
        for (int cur_index = 1; cur_index < number_array.size(); ++cur_index) {
            from_index = cur_index - 1;

            for (int i = 0; i < 10; ++i) {
                if (exact_big[i] != -1) {
                    // must number_array[exact_big[i]] > i
                    if (number_array[from_index] > i && number_array[exact_big[i]] > number_array[from_index]) {
                        exact_big[i] = from_index;
                    }
                }
                else {
                    if (number_array[from_index] > i) {
                        exact_big[i] = from_index;
                    }
                }
            }

            if (exact_big[number_array[cur_index]] != -1) {
                result_array = number_array;
                result_array[cur_index] = number_array[exact_big[number_array[cur_index]]];
                result_array[exact_big[number_array[cur_index]]] = number_array[cur_index];
                
                int end_index = cur_index;
                sort(result_array.begin(), result_array.begin() + end_index, comp);
                //
                break;
            }
        }

        if (result_array.empty()) {
            return -1;
        }

        long long value = 0;
        long long cur_p = 1;
        for (int i = 0; i < result_array.size(); ++i) {
            value += result_array[i] * cur_p;
            cur_p *= 10;

            if (value > numeric_limits<int>::max()) {
                return -1;
            }
        }

        return value;
    }
};

int main() {
    Solution s;

    std::cout << s.nextGreaterElement(1999999999) << std::endl;
    return 0;
}
