#pragma once
#include "public.h"

// 695 岛屿的最大面积（中等）
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid1[i][j] == 0 && grid2[i][j] == 1) {
                    dfs(grid2, m, n, i, j);
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid2[i][j] == 1) {
                    ++result;
                    dfs(grid2, m, n, i, j);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<int>>& grid, const int m, const int n, const int row, const int col)
    {
        if (grid[row][col] == 0) {
            return;
        }
        grid[row][col] = 0;

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