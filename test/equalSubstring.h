#pragma once
#include "public.h"

// 1208 尽可能使字符串相等（中等）
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int result = 0;
        int temp = 0;
        int left = 0;
        int right = 0;
        while (right < t.length()) {
            temp += abs(s[right] - t[right]);
            while (temp > maxCost) {
                temp -= abs(s[left] - t[left]);
                ++left;
            }
            result = max(result, right - left + 1);
            ++right;
        }
        return result;
    }
};