#pragma once
#include "public.h"

// 1254
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < n; ++i) {
            dfs(grid, m, n, 0, i);
            dfs(grid, m, n, m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            dfs(grid, m, n, i, 0);
            dfs(grid, m, n, i, n - 1);
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++result;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& grid, const int m, const int n, const int row, const int col)
    {
        if (grid[row][col] == 1) {
            return ;
        }
        grid[row][col] = 1;

        if (row - 1 >= 0) {
            dfs(grid, m, n, row - 1, col);
        }
        if (row + 1 < m) {
            dfs(grid, m, n, row + 1, col);
        }
        if (col - 1 >= 0) {
            dfs(grid, m, n, row, col - 1);
        }
        if (col + 1 < n) {
            dfs(grid, m, n, row, col + 1);
        }
    }
};
