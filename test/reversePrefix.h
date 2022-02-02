#pragma once
#include "public.h"

// 2000
class Solution {
public:
    string reversePrefix(string word, char ch)
    {
        int index = 0;
        string tmp;
        for (int i = 0; i < word.length(); ++i) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }
        if (index == 0) {
            return word;
        }
        tmp = word.substr(0, index + 1);
        reverse(tmp.begin(), tmp.end());
        tmp += word.substr(index + 1);
        return tmp;
    }
};
