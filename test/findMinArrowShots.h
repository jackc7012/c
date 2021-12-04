#pragma once
#include "public.h"

// 452
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.size() == 0) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const pair<int, int>& a1, const pair<int, int>& a2){return a1.second < a2.second;});
        int arrow = 1;
        int arrow_x = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] > arrow_x) {
                ++arrow;
                arrow_x = points[i][1];
            }
        }
        return arrow;
    }
};
