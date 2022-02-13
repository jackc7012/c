#pragma once
#include "public.h"

// 42 ½ÓÓêË®£¨À§ÄÑ£©
class Solution {
public:
    int trap(const vector<int>& height) {
        stack<int> temp;
        vector<int> c(height);
        c.push_back(0);
        int result = 0;
        for (int i = 0; i < c.size(); ++i) {
            while (!temp.empty() && c[temp.top()] < c[i]) {
                int index = temp.top();
                temp.pop();
                if (!temp.empty()) {
                    result += (i - temp.top() - 1) * (min(c[temp.top()], c[i]) - c[index]);
                }
            }
            temp.push(i);
        }
        return result;
    }
};

