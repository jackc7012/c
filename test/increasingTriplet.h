#pragma once
#include "public.h"

// 334
class Solution {
public:
    bool increasingTriplet(const vector<int>& nums)
    {
        if (nums.size() < 3) {
            return false;
        }
        int num1 = nums[0];
        int num2 = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > num2) {
                return true;
            } else if (nums[i] > num1) {
                num2 = nums[i];
            } else {
                num1 = nums[i];
            }
        }
        return false;
    }
};
