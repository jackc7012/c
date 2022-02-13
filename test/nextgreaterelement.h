#pragma once
#include "public.h"

// 503 下一个更大元素II（中等）
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        int size = nums.size();
        stack<int> temp;
        vector<int> result(size, -1);
        for (int i = 0; i < size * 2; ++i) {
            while (!temp.empty() && nums[temp.top()] < nums[i % size]) {
                auto t = temp.top();
                temp.pop();
                result[t] = nums[i % size];
            }
            temp.push(i % size);
        }
        return result;
    }
};
