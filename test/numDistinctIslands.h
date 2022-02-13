#pragma once
#include "public.h"

// 694 不同岛屿的数量（中等）
class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        set<string> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    string tmp;
                    dfs(grid, m, n, i, j, tmp, "step");
                    result.insert(tmp);
                }      
            }
        }
        return result.size();
    }

private:
    void dfs(vector<vector<int>>& grid, const int m, const int n, const int row, const int col, string &tmp, const string dir)
    {
        if (grid[row][col] == 0) {
            return;
        }
        grid[row][col] = 0;
        tmp += dir;

        if (row - 1 >= 0) {
            dfs(grid, m, n, row - 1, col, tmp, "up");
        }
        if (row + 1 < m) {
            dfs(grid, m, n, row + 1, col, tmp, "down");
        }
        if (col - 1 >= 0) {
            dfs(grid, m, n, row, col - 1, tmp, "left");
        }
        if (col + 1 < n) {
            dfs(grid, m, n, row, col + 1, tmp, "right");
        }
    }
};