#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;
// DP or dfs

/******** DFS Implementation cost to much time **********/
//class Solution {
//public:
    //void dfs(const unordered_set<string> & word_dict, const string &source_str, vector<vector<string>> & mid_saved, string cur_str, vector<vector<string>> & results, vector<string> & v, int start) {
        //if (start == source_str.size() && cur_str.length() == 0) {
            //// search finished
            //if (v.size() > 0) {
                //results.push_back(v);
            //}
            //return;
        //}

        //for (int i = start; i < source_str.size(); ++i) {
            //cur_str = cur_str + source_str[i];
            //if (word_dict.find(cur_str) != word_dict.end()) {
                //// find one
                //v.push_back(cur_str);
                //dfs(word_dict, source_str, "", results, v, i+1);
                //v.pop_back();
            //}
        //}
    //}
    //vector<string> wordBreak(string s, vector<string>& wordDict) {
        //vector<bool> s_exists(256, false);
        //vector<bool> d_exists(256, false);

        //for (char c:s) {
            //s_exists[c] = true;
        //}

        //for (string cur_s:wordDict) {
            //for (char c:cur_s) {
                //d_exists[c] = true;
            //}
        //}

        //for (int i = 0; i < 256; ++i) {
            //if (s_exists[i] && !d_exists[i]) {
                //return vector<string>();
            //}
        //}

        //unordered_set<string> word_dict;
        //word_dict.reserve(wordDict.size());
        //for (string word:wordDict) {
            //word_dict.insert(word);
        //}
        
        //vector<vector<string>> results;
        //vector<string> v;

        //dfs(word_dict, s, "", results, v, 0);

        //vector<string> str_results;
        //for (vector<string> & cur_result:results) {
            //string cur_str("");
            //for (int i = 0; i < cur_result.size() - 1; ++i) {
                //cur_str = cur_str + cur_result[i] + " ";
            //}
            //cur_str = cur_str + cur_result[cur_result.size() - 1];

            //str_results.push_back(cur_str);
        //}

        //return str_results;
    //}
//};

/********************** DP and DFS Implemetation *************************/
/********************* Cause DFS will find the wrong case fast *********************/
class Solution {
public:
    unordered_map<int, vector<string>> dp;
    int max_length;

    vector<string> dfs(const unordered_set<string>& word_dict, const string& s, int start) {
        if (dp.find(start) != dp.end()) {
            return dp[start];
        }

        vector<string> res;
        // handle the end == s.length() case
        if (word_dict.find(s.substr(start)) != word_dict.end()) {
            res.push_back(s.substr(start));
        }

        for (int end = start+1; end < s.length(); ++end) {
            if (end - start > max_length) {
                break;
            }

            string cur_str = s.substr(start, end-start);

            if (word_dict.find(cur_str) != word_dict.end()) {
                // is a string in the dict
                vector<string> next_res = dfs(word_dict, s, end);
                for (string next_str:next_res) {
                    res.push_back(cur_str + " " + next_str);
                }
            }
        }

        dp[start] = res;
        return dp[start];
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        max_length = 0;
        unordered_set<string> word_dict(wordDict.begin(), wordDict.end());
        for (string cur_s:wordDict) {
            if (cur_s.length() > max_length) {
                max_length = cur_s.length();
            }
        }
        return dfs(word_dict, s, 0);
    }
};
/*******************************************************************************************/

int main () {

    // The case only DP of DFS won't work;
    //string s("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //vector<string> wordDict({"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"});
    
    string s("pineapplepenapple");
    vector<string> wordDict({"apple", "pen", "applepen", "pine", "pineapple"});
    Solution S;

    vector<string> results = S.wordBreak(s, wordDict);
    for (string & cur_str:results) {
        cout << cur_str << endl;
    }

    return 0;
}
