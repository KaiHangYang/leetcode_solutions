#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        if (worker.empty()) {
            return 0;
        }
        vector<int> idxs(profit.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(), [&profit](int i, int j) {return profit[i] > profit[j];});
        sort(worker.begin(), worker.end(), [](int i, int j){return i > j;});
        int total = 0;
        int cur_person = 0;
        for (int i = 0; i < idxs.size(); ++i) {
            if (worker[cur_person] >= difficulty[idxs[i]]) {
                while (cur_person < worker.size() && worker[cur_person] >= difficulty[idxs[i]]) {
                    total += profit[idxs[i]];
                    cur_person +=1;
                }
                if (cur_person >= worker.size()) {
                    break;
                }
            }
        }
        return total;
    }
};

int main() {
    Solution s;
    vector<int> difficulty({2,4,6,8,10});
    vector<int> profit({10,20,30,40,50});
    vector<int> worker({4,5,6,7});
    cout << s.maxProfitAssignment(difficulty, profit, worker);
    return 0;
}