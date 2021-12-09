#pragma once
#include "public.h"

// 5
class Solution {
public:
    string longestPalindrome(const string &s)
    {
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            ++right;
            
        }
    }

private:
    bool IsPalindrome(const string& s)
    {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
