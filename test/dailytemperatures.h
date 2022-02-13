#pragma once
#include "public.h"

// 739 每日温度（中等）
class Solution {
public:
    vector<int> dailyTemperatures(const vector<int>& T) {
        stack<int> temp;
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            while (!temp.empty() && T[i] > T[temp.top()]) {
                auto t = temp.top();
                temp.pop();
                result[t] = i - t;
            }
            temp.push(i);
        }
        return result;
    }
};