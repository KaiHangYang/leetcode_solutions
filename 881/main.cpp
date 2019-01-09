#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
//所谓的贪心两点法，很好理解

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int right = people.size() - 1;
        int left = 0;
        int total_num = 0;

        while (left < right) {
            if (people[left] + people[right] <= limit) {
                ++total_num;
                ++left;
                --right;
            }
            else {
                // 这里是理解的关键
                ++total_num;
                --right;
            }
        }
        if (left == right) {
            ++total_num;
        }
        return total_num;
    }
};

int main() {
    
}
