#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        /********* First strip the string **********/
        s = strip(s);
        if (s.length() == 0) {
            return false;
        }

        /********* First check the character appeared *********/
        int n_e = 0;
        int n_posneg = 0;
        int n_dot = 0;
        bool is_number = true;

        int pos_e = -1;
        std::vector<int> pos_posneg;
        int pos_dot = -1;

        string all_string("0123456789-+e.");

        bool has_number[2] = {false, false};

        for (int i = 0; i < s.length(); ++i) {
            if (all_string.find(s[i]) == string::npos) {
                // contain the str not belong to the valid character set
                return false;
            }
            else {
                if (s[i] == '.') {
                    pos_dot = i;
                    n_dot += 1;
                }
                else if(s[i] == 'e') {
                    pos_e = i;
                    n_e += 1;
                }
                else if (s[i] == '+' || s[i] == '-') {
                    pos_posneg.push_back(i);
                    n_posneg += 1;
                }
                else {
                    if (n_e == 0) {
                        has_number[0] = true;
                    }
                    else {
                        has_number[1] = true;
                    }
                }
            }
        }

        // filter the count error
        if (n_e > 1 || n_dot > 1 || n_posneg > 2 || (n_e == 0 && n_posneg > 1)) {
            return false;
        }
        /** +- check **/
        if (!(n_posneg == 0 || (n_posneg == 1 && (pos_posneg[0] == 0 || pos_posneg[0] == pos_e+1)) || (n_posneg == 2 && ((pos_posneg[0] == 0 && pos_posneg[1] == pos_e+1) || (pos_posneg[1] == 0 && pos_posneg[0] == pos_e+1))))) {
            return false;
        }
        /**************/
        /** . check **/
        if (n_e == 1 && pos_dot > pos_e) {
            return false;
        }
        /*************/
        /** e check **/
        if (!(n_e == 1 && has_number[0] && has_number[1] || n_e == 0 && has_number[0])) {
            return false;
        }
        /*************/
        

        return true;
    }

    string strip(string s) {
        int start_pos, end_pos;
        for (start_pos = 0; start_pos < s.length(); ++start_pos) {
            if (s[start_pos] != ' ') {
                break;
            }
        }

        for (end_pos = s.length() - 1; end_pos >= 0; --end_pos) {
            if (s[end_pos] != ' ') {
                break;
            }
        }

        return s.substr(start_pos, end_pos - start_pos + 1);
    }
};


int main() {
    Solution s;
    vector<pair<string, bool>> test_case({
            pair<string, bool>("0",true),
            pair<string, bool>(" 0.1   ", true),
            pair<string, bool>("abc", false),
            pair<string, bool>("95a54e53", false),
            pair<string, bool>("1 a", false),
            pair<string, bool>("-+3",  false),
            pair<string, bool>(" --6 ",  false),
            pair<string, bool>("53.5e93",  true),
            pair<string, bool>(" 99e2.5 ",  false),
            pair<string, bool>(" 6e-1",  true),
            pair<string, bool>("e3",  false),
            pair<string, bool>(" 1e",  false),
            pair<string, bool>(" -90e3   ", true),
            pair<string, bool>("2e10", true),
            });

    for (auto cur_case:test_case) {
        std::cout << cur_case.first << " " << std::boolalpha << cur_case.second << std::endl;
        assert(s.isNumber(cur_case.first) == cur_case.second);
    }

    return 0;
}
