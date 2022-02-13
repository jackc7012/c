#pragma once
#include "public.h"

// 45 ÌøÔ¾ÓÎÏ·II£¨ÖĞµÈ£©
class Solution {
public:
    int jump(const vector<int>& nums)
    {
        int size = nums.size();
        int step = 0;
        int dist = 0;
        int end = 0;
        for (int i = 0; i < size - 1; ++i) {
            dist = max(dist, i + nums[i]);
            if (i == end) {
                end = dist;
                ++step;
            }
        }
        return step;
    }
};
