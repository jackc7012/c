#pragma once
#include "public.h"

// 47 全排列II（中等）
class Solution {
public:
    vector<vector<int>> permuteUnique(const vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> visit(nums.size(), 0);
        traceBack(nums, 0, tmp, visit, res);
        sort(res.begin(), res.end());
        auto iter = unique(res.begin(), res.end());
        res.erase(iter, res.end());
        return res;
    }

private:
    void traceBack(const vector<int>& nums, const int index, vector<int>& tmp, vector<int> &visit, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i] == 1) {
                continue;
            }
            tmp.push_back(nums[i]);
            visit[i] = 1;
            traceBack(nums, 0, tmp, visit, res);
            tmp.pop_back();
            visit[i] = 0;
        }
    }
};