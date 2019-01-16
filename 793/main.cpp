#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int preimageSizeFZF(int K) {
        long long int p5 = 1;
        long long int p = 1;
        
        while (p < K) {
            p5 *= 5;
            p += p5;
        }
        
        while (p > 1) {
            if (K % p == p - 1)
                return 0;
            K -= K / p;
            p -= p5;
            p5 /= 5;
        }
        
        return 5;
    }
};

//class Solution {
//public:
    //int preimageSizeFZF(int K) {
        //int total_num = K==0?2:0;

        //vector<int> arr;
        //arr = vector<int>({0, 0, 0}); // f(1)

        //int n = 2;

        //while (true) {
            //int tmp_n = n;

            //while (tmp_n % 10 == 0) {
                //++arr[2];
                //tmp_n /= 10;
            //}
            //while (tmp_n % 5 == 0) {
                //++arr[1];
                //tmp_n /= 5;
            //}
            //while (tmp_n % 2 == 0) {
                //++arr[0];
                //tmp_n /= 2;
            //}

            //while (arr[0] > 0 && arr[1] > 0) {
                //++arr[2];
                //--arr[0];
                //--arr[1];
            //}

            //if (arr[2] == K) {
                //++total_num;
            //}
            //else if (arr[2] > K) {
                //break;
            //}

            //++n;
        //}

        //return total_num;
    //}
//};

int main() {
    Solution s;
    std::cout << s.preimageSizeFZF(66550376) << std::endl;
    return 0;
}
