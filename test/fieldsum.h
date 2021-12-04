#pragma once
#include "public.h"

class Solution {
public:
    int FieldSum(const vector<int>& v)
    {
        stack<int> temp;
        vector<int> result(v);
        int tmp = 0;
        for (int i = v.size() - 1; i >= 0; --i) {
            int c = 0;
            while (!temp.empty() && v[temp.top()] < v[i]) {
                ++c; 
                temp.pop();
            }
            tmp += (temp.empty() ? 0 : c);
            temp.push(i);
        }
        return tmp;
    }
};