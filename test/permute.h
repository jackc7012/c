#pragma once
#include "public.h"

// 46
class Solution {
public:
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        traceBack(nums, 0, tmp, res);
        return res;
    }

private:
    void traceBack(const vector<int>& nums, const int index, vector<int> &tmp, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return ;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end()) {
                continue;
            }
            tmp.push_back(nums[i]);
            traceBack(nums, 0, tmp, res);
            tmp.pop_back();
        }
    }
};