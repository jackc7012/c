#pragma once
#include "public.h"

// 76
class Solution {
public:
    string minWindow(const string &s, const string &t) {
        unordered_map<char, int> window, need;
        for (auto item : t) {
            ++need[item];
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                ++window[c];
                if (need.find(c)->second == window[c]) {
                    ++valid;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                ++left;
                if (need.count(d)) {
                    if (need.find(d)->second == window[d]) {
                        --valid;
                    }
                    --window[d];
                }
            }
        }
        return ((len == INT_MAX) ? "" : s.substr(start, len));
    }
};