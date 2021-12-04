#pragma once
#include "public.h"

// 695
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int tmp = 0;
                    dfs(grid, m, n, i, j, tmp);
                    result = max(result, tmp);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& grid, const int m, const int n, const int row, const int col, int &tmp) {
        ++tmp;
        grid[row][col] = 0;

        if (row - 1 >= 0 && grid[row - 1][col] == 1) { dfs(grid, m, n, row - 1, col, tmp); }
        if (row + 1 < m && grid[row + 1][col] == 1) { dfs(grid, m, n, row + 1, col, tmp); }
        if (col - 1 >= 0 && grid[row][col - 1] == 1) { dfs(grid, m, n, row, col - 1, tmp); }
        if (col + 1 < n && grid[row][col + 1] == 1) { dfs(grid, m, n, row, col + 1, tmp); }
    }

};