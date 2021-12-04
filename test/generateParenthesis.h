#pragma once
#include "public.h"

// 22
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> tmp;
        string temp;
        dfs(n ,tmp, temp, 0, 0);
        return tmp;
    }

private:
    void dfs(int n, vector<string>& tmp, string& temp, int left, int right) {
        if (right > left) {
            return;
        }
        if (temp.size() == n * 2) {
            tmp.emplace_back(temp);
            return;
        }

        if (left < n) {
            temp += '(';
            dfs(n, tmp, temp, left + 1, right);
            temp = temp.substr(0, temp.size() - 1);
        }
        if (right < n) {
            temp += ')';
            dfs(n, tmp, temp, left, right + 1);
            temp = temp.substr(0, temp.size() - 1);
        }
    }
};