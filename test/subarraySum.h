#pragma once
#include "public.h"

// 560
class Solution {
public:
    int subarraySum(const vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = 0;
            for (int j = i; j >= 0; --j) {
                tmp += nums[j];
                if (tmp == k) {
                    ++result;
                }
            }
        }
        return result;
    }
};