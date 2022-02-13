#pragma once
#include "public.h"

// 1219
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        set<pair<int, int>> visited;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) {
                    int sum = dfs(grid, m, n, i, j, visited);
                    result = max(result, sum);
                }
            }
        }
        return result;
    }

private:
    int dfs(vector<vector<int>>& grid, int m, int n, int row, int col, set<pair<int, int>> &visited)
    {
        if (grid[row][col] == 0 || visited.find(make_pair(row, col)) != visited.end()) {
            return 0;
        }
        int sum = 0;
        visited.insert(make_pair(row, col));
        for (int i = 0; i < 4; ++i) {
            int x = row + dir[i][0];
            int y = col + dir[i][1];
            if (x >= 0 && y >= 0 && x < m && y < n) {
                int result = dfs(grid, m, n, x, y, visited);
                sum = max(sum, result);
            }
        }
        visited.erase(make_pair(row, col));
        return sum + grid[row][col];
    }

    const int dir[4][2]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
