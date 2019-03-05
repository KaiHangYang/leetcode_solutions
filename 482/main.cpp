#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string result("");
        stack<char> s;
        for (char ch:S) {
            if (ch >= 'a' && ch <= 'z') {
                s.push(ch - 'a' + 'A');
            }
            else if (ch >= 'A' && ch <= 'Z') {
                s.push(ch);
            }
            else if (ch >= '0' && ch <= '9') {
                s.push(ch);
            }
        }
        
        while (!s.empty()) {
            for (int i = 0; i < K; ++i) {
                result = s.top() + result;
                s.pop();
                if (s.empty()) {
                    break;
                }
            }
            
            if (!s.empty()) {
                result = "-" + result;
            }
        }
        
        return result;
    }
};

int main() {
    
    return 0;
}
