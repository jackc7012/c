#pragma once
#include "public.h"

// 1094
class Solution {
public:
    bool carPooling(const vector<vector<int>>& trips, int capacity) {
        vector<int> tmp(1001, 0);
        for (int i = 0; i < trips.size(); ++i) {
            tmp[trips[i][1]] += trips[i][0];
            tmp[trips[i][2]] -= trips[i][0];
        }

        int result = 0;
        for (int i = 0; i < tmp.size(); ++i) {
            result += tmp[i];
            if (result > capacity) {
                return false;
            }
        }
        return true;
    }
};
