#pragma once
#include "public.h"

// 39
class Solution {
public:
    vector<vector<int>> combinationSum(const vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<int> temp(candidates);
        sort(temp.begin(), temp.end());
        traceBack(temp, target, 0, temp.size() - 1, tmp, res);
        return res;
    }

private:
    void traceBack(const vector<int>& candidates, const int target, const int sum, const int index, vector<int> &tmp, vector<vector<int>>& res) {
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        else if (sum > target) {
            return;
        }

        for (int i = index; i >= 0; --i) {
            if ((target - sum) < candidates[i]) {
                continue;
            }
            tmp.push_back(candidates[i]);
            traceBack(candidates, target, sum + candidates[i], i, tmp, res);
            tmp.pop_back();
        }
    }
};