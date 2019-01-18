class Solution {
public:
    bool judgeCircle(string moves) {
        int total_h = 0;
        int total_v = 0;
        for (char c:moves) {
            if (c == 'L') {
                --total_h;
            }
            else if (c == 'R') {
                ++total_h;
            }
            else if (c == 'U') {
                --total_v;
            }
            else if (c == 'D') {
                ++ total_v;
            }
        }
        
        return !total_v && !total_h;
    }
};
