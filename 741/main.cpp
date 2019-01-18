#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/******* Below is only the single path solution *********/
//class Solution {
//public:

    //int cherryPickup(vector<vector<int>>& grid) {
        //int N = grid.size();
        //int total_cherry = 0;

        //vector<vector<pair<int, int>>> bp_forward;

        //for (int i = 0; i < N; ++i) {
            //bp_forward.push_back(vector<pair<int, int>>(N, pair<int, int>(0, 0)));
        //}

        //for (int i = 0; i < N; ++i) {
            //if (i == 0) {
                //bp_forward[i][i] = pair<int, int>(grid[i][i], -1);
            //}
            //else {
                //for (int j = 0; j <= i; ++j) {
                    //if (j == 0) {
                        //// horizon
                        //if (grid[i][j] != -1 && bp_forward[i-1][j].first != -1) {
                            //bp_forward[i][j] = pair<int, int>(bp_forward[i-1][j].first + grid[i][j], N * (i-1));
                        //}
                        //else {
                            //// the thorn
                            //bp_forward[i][j] = pair<int, int>(-1, -1);
                        //}

                        //// vertical
                        //if (grid[j][i] != -1 && bp_forward[j][i-1].first != -1) {
                            //bp_forward[j][i] = pair<int, int>(bp_forward[j][i-1].first + grid[j][i], (i-1));
                        //}
                        //else {
                            //bp_forward[j][i] = pair<int, int>(-1, -1);
                        //}
                    //}
                    //else {
                        //for (int tmp = 0; tmp < 2; ++tmp) {
                            //int x, y;
                            //if (tmp == 0) {
                                //y = i;
                                //x = j;
                            //}
                            //else {
                                //y = j;
                                //x = i;
                                //if (x == y) {
                                    //break;
                                //}
                            //}

                            //if (grid[y][x] == -1 || bp_forward[y-1][x].first == -1 && bp_forward[y][x-1].first == -1) {
                                //// can't reach here
                                //bp_forward[y][x] = pair<int, int>(-1, -1);
                            //}
                            //else if (bp_forward[y-1][x].first != -1 && bp_forward[y][x-1].first != -1) {
                            
                                //pair<int, int> bl_elm = pair<int, int>(bp_forward[y][x-1].first + grid[y][x], y * N + x - 1);
                                //pair<int, int> tr_elm = pair<int, int>(bp_forward[y-1][x].first + grid[y][x], (y-1) * N + x);
                            
                                //if (bl_elm.first >= tr_elm.first) {
                                    //bp_forward[y][x] = bl_elm;
                                //}
                                //else {
                                    //bp_forward[y][x] = tr_elm;
                                //}
                            //}
                            //else if (bp_forward[y-1][x].first != -1) {
                                //bp_forward[y][x] = pair<int, int>(bp_forward[y-1][x].first + grid[y][x], (y-1) * N + x);
                            //}
                            //else {
                                //bp_forward[y][x] = pair<int, int>(bp_forward[y][x-1].first + grid[y][x], y * N + x - 1);
                            //}

                        //}

                    //}
                //}
            //}

        //}

        //if (bp_forward[N-1][N-1].first == -1) {
            //return 0;
        //}

        //if (cur_cycle == 1) {
            //break;
        //}

        //int x = N-1;
        //int y = N-1;
        //int cur_pos;

        //for (int i = 0; i < 2*N-1; ++i) {
            ////std::cout << "(" << y << ", " << x << ")" << endl;
            //grid[y][x] = 0;
            //cur_pos = bp_forward[y][x].second;
            //y = cur_pos / N;
            //x = cur_pos % N;
        //}
        
        //return total_cherry;
    //}
//};
/**********************************************************/
// A good implementations, but the dp array implementation is pretty tricky, I can use two dp array to do this
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int N = grid.size();
        int P_LEN = N + N - 1;
        vector<vector<int> > dp = vector<vector<int>>(N, vector<int>(N, -1));
        dp[0][0] = grid[0][0];
        
        for (int p = 2; p <= P_LEN; p++) {//p is the length of the path
            vector<vector<int> > dp2 = vector<vector<int>>(N, vector<int>(N, -1));

            for (int x1 = 0; x1 < N; ++x1) {
                for (int x2 = x1; x2 < N; ++x2) {
                    int y1 = p - 1 - x1;
                    int y2 = p - 1 - x2;
                    if (y1 < 0 || y2 < 0 || y1 >= N || y2 >= N)
                        continue;
                    if (grid[y1][x1] < 0 || grid[y2][x2] < 0) {
                        continue;
                    }   
                    int best = -1, delta = grid[y1][x1];
                    if (x1 != x2)
                        delta += grid[y2][x2];
                    if (x1 > 0 && x2 > 0 && dp[x1 - 1][x2 - 1] >= 0) //from left left
                        best = max(best, dp[x1 - 1][x2 - 1] + delta);
                    if (x1 > 0 && y2 > 0 && dp[x1 - 1][x2] >= 0) //from left up
                        best = max(best, dp[x1 - 1][x2] + delta);
                    if (y1 > 0 && x2 > 0 && dp[x1][x2 - 1] >= 0) //from up left
                        best = max(best, dp[x1][x2 - 1] + delta);
                    if (y1 > 0 && y2 > 0 && dp[x1][x2] >= 0) //from up up
                        best = max(best, dp[x1][x2] + delta);
                    dp2[x1][x2] = best;
                }
            }
            dp = dp2;
        }
        return dp[N - 1][N - 1] < 0 ? 0 : dp[N - 1][N - 1];
    }
};

int main() {

    vector<vector<int>> inputs({{1,-1,-1,-1,-1},{1,0,1,-1,-1},{0,-1,1,0,1},{1,0,1,1,0},{-1,-1,-1,1,1}});

    Solution s;

    std::cout << s.cherryPickup(inputs) << std::endl;

    return 0;
}
