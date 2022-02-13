#pragma once
#include "public.h"

// 884 两句话中的不常见单词（简单）
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        map<string, int> tmp;
        vector<string> result;
        s1 += " ";
        s2 += " ";
        while (!s1.empty()) {
            int pos = s1.find_first_of(' ');
            if (tmp.find(s1.substr(0, pos)) == tmp.end()) {
                tmp[s1.substr(0, pos)] = 1;
            } else {
                ++tmp[s1.substr(0, pos)];
            }
            s1 = s1.substr(pos + 1);
        }
        while (!s2.empty()) {
            int pos = s2.find_first_of(' ');
            if (tmp.find(s2.substr(0, pos)) == tmp.end()) {
                tmp[s2.substr(0, pos)] = 1;
            } else {
                ++tmp[s2.substr(0, pos)];
            }
            s2 = s2.substr(pos + 1);
        }
        for (auto itor = tmp.begin(); itor != tmp.end(); ++itor) {
            if (itor->second == 1) {
                result.emplace_back(itor->first);
            }
        }
        return result;
    }
};
