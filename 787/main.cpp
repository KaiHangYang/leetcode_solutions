#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>

using namespace std;

struct Comp {
    bool operator () (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        int a_city, a_k, a_price;
        int b_city, b_k, b_price;

        tie(a_city, a_k, a_price) = a;
        tie(b_city, b_k, b_price) = b;

        if (a_price > b_price) {
            return true;
        }
        else if (a_price == b_price) {
            return a_k < b_k;
        }
        else {
            return false;
        }
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // dijkstra 单源最短路径问题，不包含负权值
        vector<vector<int>> adj_table(n, vector<int>(n, -1));
        for (int i = 0; i < flights.size(); ++i) {
            adj_table[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, Comp> Q;
        Q.push(make_tuple(src, -1, 0));

        vector<vector<int>> min_price(n, vector<int>(K+1, numeric_limits<int>::max()));

        for (int i = 0; i < K+1; ++i) {
            min_price[src][i] = 0;
        }

        while (!Q.empty()) {
            int city, stops, price;
            tie(city, stops, price) = Q.top();
            Q.pop();

            if (city == dst) {
                return price;
            }

            if (stops == K) {
                continue;
            }


            for (int i = 0; i < n; ++i) {
                if (adj_table[city][i] < 0) {
                    continue;
                }

                int new_price = price + adj_table[city][i];

                if (new_price >= min_price[i][stops+1]) {
                    continue;
                }

                for (int j = stops + 1; j < K + 1; ++j) {
                    min_price[i][j] = min(new_price, min_price[i][j]);
                }

                Q.push(make_tuple(i, stops+1, new_price));

            }
        }

        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> inputs({{0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1}});
    std::cout << s.findCheapestPrice(5, inputs, 0, 2, 2);

    return 0;
}
