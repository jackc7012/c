#pragma once
#include "public.h"

// 3 无重复字串的最长子串（中等）
class Solution {
public:
    int lengthOfLongestSubstring(const string &s)
    {
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_set<char> tmp;
        while (right < s.length()) {
            while (tmp.find(s[right]) != tmp.end()) {
                tmp.erase(s[left]);
                ++left;
            }
            result = max(result, right - left + 1);
            tmp.insert(s[right]);
            ++right;
        }
        return result;
    }
};
