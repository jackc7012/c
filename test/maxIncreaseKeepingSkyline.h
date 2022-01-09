#pragma once
#include "public.h"

// 807
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid)
    {
        vector<int> north(grid.size()), west(grid.size());
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                north[i] = max(north[i], grid[i][j]);
                west[j] = max(west[j], grid[i][j]);
            }
        }
        int result = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                result += min(north[i], west[j]) - grid[i][j];
            }
        }
        return result;
    }
};
