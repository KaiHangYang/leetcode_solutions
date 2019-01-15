#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& adj_tbl, unordered_map<string, bool> & visited, vector<string>& result_path, vector<string>& v, string cur_pos, string target) {
        if (cur_pos == target || adj_tbl[cur_pos].size() == 0) {
            if (cur_pos == target) {
                // find the result
                result_path = v;
            }
            return;
        }

        for (int i = 0; i < adj_tbl[cur_pos].size(); ++i) {
            if (!result_path.empty()) {
                return;
            }

            if (visited[adj_tbl[cur_pos][i]]) {
                continue;
            }

            v.push_back(adj_tbl[cur_pos][i]);
            visited[adj_tbl[cur_pos][i]] = true;
            dfs(adj_tbl, visited, result_path, v, adj_tbl[cur_pos][i], target);
            v.pop_back();
            visited[adj_tbl[cur_pos][i]] = false;
        }
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> results;

        unordered_map<string, vector<string>> adj_tbl;
        unordered_map<string, double> val_tbl;

        unordered_map<string, bool> exists;

        for (int i = 0; i < equations.size(); ++i) {
            pair<string, string> cur_edge = equations[i];
            adj_tbl[cur_edge.first].push_back(cur_edge.second);
            val_tbl[cur_edge.first + "+" + cur_edge.second] = values[i];

            adj_tbl[cur_edge.second].push_back(cur_edge.first);
            val_tbl[cur_edge.second + "+" + cur_edge.first] = 1.0/values[i];
            exists[cur_edge.first] = true;
            exists[cur_edge.second] = true;
        }

        for (int i = 0; i < queries.size(); ++i) {
            if (!exists[queries[i].first] || !exists[queries[i].second]) {
                results.push_back(-1);
                continue;
            }
            if (queries[i].first == queries[i].second) {
                results.push_back(1);
                continue;
            }

            vector<string> result_path;
            vector<string> v;
            unordered_map<string, bool> visited;

            // from first to second first
            visited[queries[i].first] = true;
            v.push_back(queries[i].first);
            dfs(adj_tbl, visited, result_path, v, queries[i].first, queries[i].second);

            if (!result_path.empty()) {
                // find the result
                double cur_val = 1.0;

                for (int i = 0; i < result_path.size() - 1; ++i) {
                    cur_val *= val_tbl[result_path[i] + "+" + result_path[i+1]];
                }

                results.push_back(cur_val);
            }
            else {
                visited.clear();
                v.clear();
                v.push_back(queries[i].second);
                visited[queries[i].second] = true;

                dfs(adj_tbl, visited, result_path, v, queries[i].second, queries[i].first);
                if (!result_path.empty()) {
                    double cur_val = 1.0;

                    for (int i = 0; i < result_path.size() - 1; ++i) {
                        cur_val *= val_tbl[result_path[i] + "+" + result_path[i+1]];
                    }
                    results.push_back(1.0 / cur_val);
                }
                else {
                    results.push_back(-1);
                }
            }
        }

        return results;

    }
};

int main() {
    vector<pair<string, string>> equations({{"a", "b"}, {"b", "c"}});
    vector<double> values({2.0, 3.0});
    vector<pair<string, string>> queries({{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}});

    Solution s;
    vector<double> results = s.calcEquation(equations, values, queries);

    for (double v:results) {
        std::cout << v << std::endl;
    }

    return 0;
}
