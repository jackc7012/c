#pragma once
#include "public.h"

// 1109
class Solution {
public:
    vector<int> corpFlightBookings(const vector<vector<int>>& bookings, int n)
    {
        vector<int> result(n + 2);
        for (int i = 0; i < bookings.size(); ++i) {
            result[bookings[i][0]] += bookings[i][2];
            result[bookings[i][1] + 1] -= bookings[i][2];
        }
        for (int i = 1; i < result.size(); ++i) {
            result[i] = result[i - 1] + result[i];
        }
        return vector<int>(result.begin() + 1, result.end() - 1);
    }
};
