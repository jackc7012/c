#pragma once
#include "public.h"

// 1004
class Solution {
public:
    int longestOnes(const vector<int>& nums, int k)
    {
        int result = 0;
        int zeros = 0;
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) {
                ++zeros;
            }
            while (zeros > k) {
                if (nums[left] == 0) {
                    --zeros;
                }
                ++left;
            }
            result = max(result, right - left + 1);
            ++right;
        }
        return result;
    }
};
