#pragma once
#include "public.h"

// 752
class Solution {
public:
    int openLock(const vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) {
            return -1;
        }
        queue<string> tmp;
        tmp.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        for (auto item : deadends) {
            visited.insert(item);
        }

        int result = 0;
        while (!tmp.empty()) {
            int size = tmp.size();
            for (int i = 0; i < size; ++i) {
                auto s = tmp.front();
                tmp.pop();
                if (s == target) {
                    return result;
                }
                for (int j = 0; j < 4; ++j) {
                    // 向上翻转
                    string temp = upRotate(s, j);
                    if (visited.find(temp) == visited.end()) {
                        tmp.push(temp);
                        visited.insert(temp);
                    }
                    // 向下翻转
                    temp = downRotate(s, j);
                    if (visited.find(temp) == visited.end()) {
                        tmp.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            ++result;
        }
        return -1;
    }

private:
    string upRotate(const string& src, const int index) {
        string res(src);
        res[index] = (res[index] == '9' ? '0' : (res[index] + 1));
        return res;
    }

    string downRotate(const string& src, const int index) {
        string res(src);
        res[index] = (res[index] == '0' ? '9' : (res[index] - 1));
        return res;
    }
};