#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> t_count(26, 0);

        for (char ch:t) {
            ++t_count[ch-'a'];
        }

        for (char ch:s) {
            --t_count[ch-'a'];
        }

        for (int i = 0; i < t_count.size(); ++i) {
            if (t_count[i] == 1) {
                return i + 'a';
            }
        }

    }
};


int main() {
    
    return 0;
}
