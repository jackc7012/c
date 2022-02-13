#pragma once
#include "public.h"

// 383 Êê½ðÐÅ£¨¼òµ¥£©
class Solution {
public:
    bool canConstruct(const string &ransomNote, const string &magazine)
    {
        map<char, int> tmp;
        for (const auto& i : magazine) {
            if (!tmp.count(i)) {
                tmp[i] = 1;
            } else {
                ++tmp[i];
            }
        }
        for (const auto& i : ransomNote) {
            if (!tmp.count(i)) {
                return false;
            } else {
                if (tmp[i] == 0) {
                    return false;
                }
                --tmp[i];
            }
        }
        return true;
    }
};
