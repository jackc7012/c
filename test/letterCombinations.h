#pragma once
#include "public.h"

// 17
class Solution {
public:
    vector<string> letterCombinations(const string &digits) {
        string tmp;
        vector<string> res;
        if (digits.length() != 0) {
            traceBack(digits, 0, tmp, res);
        }
        return res;
    }

private:
    void traceBack(const string& digits, const int index, string& tmp, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(tmp);
            return;
        }

        for (auto item : numToString[digits[index]]) {
            tmp += item;
            traceBack(digits, index + 1, tmp, res);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }

    unordered_map<char, string> numToString{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                              {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};