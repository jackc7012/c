#pragma once
#include "public.h"

// 84 柱状图中最大的矩形（困难）
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<int> temp;
        vector<int> widths(heights.size());
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!temp.empty() && heights[i] < heights[temp.top()]) {
                auto t = temp.top();
                temp.pop();
                if (temp.empty()) {
                    widths[t] = i;
                } else {
                    widths[t] = i - temp.top() - 1;
                }
            }
            temp.push(i);
        }
        int result = 0;
        for (int i = 0; i < heights.size() - 1; ++i) {
            result = max(result, heights[i] * widths[i]);
        }
        return result;
    }
};
