#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool my_cmp(const int &a, const int &b) {
    if (a >= b) {
        return true;
    }
    else {
        return false;
    }
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        sort(piles.begin(), piles.end(), my_cmp);
        // binary search
        int K = piles[0];
        int start = 0;
        int end = piles.size() - 1;
        int mid = (end + start) / 2;

        int mid_time = 0;
        bool one_elm = start == end;

        while (true) {
            mid_time = count_hours(piles, piles[mid]);
            if (mid_time == H) {
                // find the exactly K
                return piles[mid];
            }

            if (start == end - 1 || one_elm) {
                // find the range to get the mid K
                int tmp_time = count_hours(piles, piles[end]);
                if (tmp_time == H) {
                    return piles[end];
                }
                else {
                    // Then use binary search to find a good one
                    int inner_start, inner_end;

                    if (tmp_time < H || one_elm) {
                        // T(piles[start] <= T(piles[end]) < H)
                        inner_start = piles[end];
                        inner_end = 1;
                    }
                    else {
                        // T(piles[start] < H < T(piles[end]))
                        inner_start = piles[start];
                        inner_end = piles[end];
                    }
                    
                    int inner_mid = (inner_start + inner_end) / 2;
                    int inner_mid_time;

                    while (true) {
                        inner_mid_time = count_hours(piles, inner_mid);

                        if (inner_mid_time == H) {
                            return inner_mid;
                        }

                        if (inner_start == inner_end + 1) {
                            // inner_mid_time is inner_end's time
                            if (inner_mid_time < H) {
                                return inner_end;
                            }
                            else {
                                return inner_start;
                            }
                        }

                        if (inner_mid_time > H) {
                            inner_end = inner_mid;
                            inner_mid = (inner_start + inner_end) / 2;
                        }
                        else {
                            inner_start = inner_mid;
                            inner_mid = (inner_start + inner_end) / 2;
                        }
                    }
                }
            }

            if (mid_time > H) {
                end = mid;
                mid = (start + end) / 2;
            }
            else {
                // mid_time < H
                start = mid;
                mid = (start + end) / 2;
            }
        }

        return K;
    }

    int count_hours(const vector<int> & piles, int K) {
        int total_hour = 0;
        for (int i = 0; i < piles.size(); ++i) {
            total_hour += static_cast<int>(ceil(piles[i] / static_cast<float>(K)));
        }

        return total_hour;
    }
};

int main () {
    vector<int> piles({30});
    int H = 7;
    Solution s;
    std::cout << s.minEatingSpeed(piles, H) << std::endl;
    return 0;
}

