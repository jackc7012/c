#pragma once
#include "public.h"

// 93
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        if (s.length() > 12) {
            return {};
        }
        string result;
        FindResult(s, 0, 0, result, results);
        return results;
    }

private:
    void FindResult(const std::string& s, const int index, const int num, string &result, vector<string> results)
    {
        if (num == 3) {
            results.emplace_back(result);
            return ;
        }

        for (int i = index; i < s.length(); ++i) {
            
        }
    }

    bool JudgeValid()
};
