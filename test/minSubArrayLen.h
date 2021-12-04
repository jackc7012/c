#pragma once
#include "public.h"

// 209
class Solution {
public:
    int minSubArrayLen(int target, const vector<int>& nums)
    {
        int result = INT_MAX;
        int temp = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            temp += nums[right];
            while (temp >= target) {
                temp -= nums[left];
                result = min(result, right - left + 1);
                ++left;
            }
            ++right;
        }
        return (result == INT_MAX ? 0 : result);
    }
};
