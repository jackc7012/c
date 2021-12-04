#pragma once
#include "public.h"

// 934
class Solution {
public:
    int shortestBridge(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> c(grid);
        queue<pair<int, int>> temp;
        // 找到其中一个岛
        bool flag = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (c[i][j] == 1) {
                    dfs(c, m, n, i, j, temp);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }

        // 向外拓展寻找另外一个岛
        int result = bfs(c, m, n, temp);
        return result - 1;
    }

private:
    void dfs(vector<vector<int>>& grid, const int m, const int n, const int row, const int col, queue<pair<int, int>> &temp) {
        grid[row][col] = 2;
        temp.push({row, col});

        if (row - 1 >= 0 && grid[row - 1][col] == 1) { dfs(grid, m, n, row - 1, col, temp); }
        if (row + 1 < m && grid[row + 1][col] == 1) { dfs(grid, m, n, row + 1, col, temp); }
        if (col - 1 >= 0 && grid[row][col - 1] == 1) { dfs(grid, m, n, row, col - 1, temp); }
        if (col + 1 < n && grid[row][col + 1] == 1) { dfs(grid, m, n, row, col + 1, temp); }
    }

    int bfs(vector<vector<int>>& grid, const int m, const int n, queue<pair<int, int>>& temp) {
        vector<vector<int>> cc(grid);
        int result = 0;
        while (!temp.empty()) {
            ++result;
            int size = temp.size();
            for (int i = 0; i < size; ++i) {
                auto a = temp.front();
                temp.pop();
                int x = a.first;
                int y = a.second;
                for (int j = 0; j < 4; ++j) {
                    int new_x = x + pos[j][0];
                    int new_y = y + pos[j][1];
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n) {
                        if (cc[new_x][new_y] == 2) {
                            continue;
                        }
                        else if (cc[new_x][new_y] == 1) {
                            return result;
                        }
                        cc[new_x][new_y] = 2;
                        temp.push({new_x, new_y});
                    }
                }
            }
        }
        return -1;
    }

    int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
