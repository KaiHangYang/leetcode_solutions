#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.size() != b.size()) {
            return max(a.size(), b.size());
        }
        else {
            return (a == b)?-1:a.size();
        }
    }
};

int main() {
    
    return 0;
}
