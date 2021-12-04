#pragma once
#include "public.h"

// 200
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++result;
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>>& grid, const int m, const int n, const int row, const int col) {
        grid[row][col] = '0';

        if (row - 1 >= 0 && grid[row - 1][col] == '1') { dfs(grid, m, n, row - 1, col); }
        if (row + 1 < m && grid[row + 1][col] == '1') { dfs(grid, m, n, row + 1, col); }
        if (col - 1 >= 0 && grid[row][col - 1] == '1') { dfs(grid, m, n, row, col - 1); }
        if (col + 1 < n && grid[row][col + 1] == '1') { dfs(grid, m, n, row, col + 1); }
    }

};