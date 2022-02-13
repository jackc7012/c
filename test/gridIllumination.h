#pragma once
#include "public.h"

// 1001
// 42/45
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries)
    {
        set<pair<long long, long long>> points;
        unordered_map<int, int> row, col, main_line, sec_line;
        for (int i = 0; i < lamps.size(); ++i) {
            if (points.find(make_pair(lamps[i][0], lamps[i][1])) == points.end()) {
                points.insert(make_pair(lamps[i][0], lamps[i][1]));
                ++row[lamps[i][0]];
                ++col[lamps[i][1]];
                ++main_line[lamps[i][0] - lamps[i][1]];
                ++sec_line[lamps[i][0] + lamps[i][1]];
            }
        }
        vector<int> result(queries.size(), 0);
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (row[x] || col[y] || main_line[x - y] || sec_line[x + y]) {
                result[i] = 1;
            }
            for (int j = 0; j < 9; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if (points.find(make_pair(nx, ny)) != points.end()) {
                    points.erase(make_pair(nx, ny));
                    row[nx]--;
                    col[ny]--;
                    main_line[nx + ny]--;
                    sec_line[nx - ny]--;
                }
            }
        }
        return result;
    }

private:
    int N;
    const int dx[9] = {-1, 0, 1, 0, -1, 1, 1, -1, 0};
    const int dy[9] = {0, -1, 0, 1, -1, 1, -1, 1, 0};
};