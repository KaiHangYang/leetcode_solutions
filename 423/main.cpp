#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//class Solution {
//public:
    //vector<string> digital_array;
    //vector<int> digital_size;
    //int total_len;
    //vector<int> letter_array;

    //bool add_number(int num, int size) {
        //vector<int> tmp_letter_array(letter_array.begin(), letter_array.end());

        //for (char c:digital_array[num]) {
            //tmp_letter_array[c-'a'] -= size;

            //if (tmp_letter_array[c-'a'] < 0) {
                //return false;
            //}
        //}

        //letter_array = tmp_letter_array;
        //digital_size[num] += size;
        //return true;
    //}

    //void remove_number(int num, int size) {
        //for (char c:digital_array[num]) {
            //letter_array[c-'a'] += size;
        //}

        //digital_size[num] -= size;
    //}

    //void dfs(vector<int> & result, int cur_num, int cur_size) {
        //if (cur_num > 9 || cur_size == total_len) {
            //if (cur_size == total_len) {
                //result = digital_size;
            //}
            //return;
        //}

        //int size = 0;
        //while (true) {
            //if (result.size() != 0) {
                //break;
            //}

            //if (add_number(cur_num, size)) {
                //dfs(result, cur_num+1, cur_size + size * digital_array[cur_num].length());
                //remove_number(cur_num, size);
            //}
            //else {
                //break;
            //}

            //++size;
        //}
    //}

    //string originalDigits(string s) {
        //total_len = s.length();
        //digital_array = vector<string>({"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"});
        //digital_size = vector<int>(digital_array.size(), 0);
        //letter_array = vector<int>(26, 0);

        //for (char c:s) {
            //letter_array[c-'a'] += 1;
        //}

        //vector<int> result;
        //dfs(result, 0, 0);

        //string result_str("");

        //for (int i=0; i < result.size(); ++i) {
            //for (int j=0; j < result[i]; ++j) {
                //result_str += to_string(i);
            //}
        //}

        //return result_str;
    //}
//};
//

/************ The solution by using the things useful in the number string ****************/
class Solution {
public:
    vector<int> letter_array;
    string originalDigits(string s) {
        vector<int> results(10, 0);
        string result_str("");
        letter_array = vector<int>(26, 0);
        for (char c:s) {
            ++letter_array[c-'a'];
        }

        results[6] = count("six", 'x');
        results[0] = count("zero", 'z');
        results[8] = count("eight", 'g');
        results[4] = count("four", 'u');
        results[2] = count("two", 'w');
        results[1] = count("one", 'o');
        results[5] = count("five", 'f');
        results[9] = count("nine", 'i');
        results[7] = count("seven", 's');
        results[3] = count("three", 't');

        for (int i = 0; i < 10; ++i) {
            result_str += string(results[i], i + '0');
        }

        return result_str;
    }


    int count(string s, char c) {
        int num = letter_array[c-'a'];

        for (char tmp_c:s) {
            letter_array[tmp_c-'a'] -= num;
        }

        return num;
    }
};

int main() {
    Solution s;

    std::cout << s.originalDigits("zeroonetwothreefourfivesixseveneightnine") << std::endl;
}
