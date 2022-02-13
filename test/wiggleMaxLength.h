#pragma once
#include "public.h"

// 376 摆动序列（中等）
class Solution {
public:
    int wiggleMaxLength(const vector<int>& nums)
    {
        if (nums.size() == 1) {
            return 1;
        } else if (nums.size() == 2 && nums[0] != nums[1]) {
            return 2;
        }
        int diff = nums[1] - nums[0];
        int step = (diff == 0 ? 1 : 2);
        for (int i = 2; i < nums.size(); ++i) {
            int num = nums[i] - nums[i - 1];
            if ((diff <= 0 && num > 0) || (diff >= 0 && num < 0)) {
                ++step;
            }
            diff = num;
        }
        return step;
    }
};
