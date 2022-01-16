#pragma once
#include "public.h"

// 373
class Solution {
public:
    vector<vector<int>> kSmallestPairs(const vector<int>& nums1, const vector<int>& nums2, int k)
    {
        auto cmp = [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b)              //**********
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];            //**********
        };
        vector<vector<int>> ans;
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        for (int i = 0; i < min(k, m); i++)
            que.emplace(i, 0);
        while (!que.empty() && k > 0) {
            auto c = que.top();
            que.pop();
            ans.push_back(vector<int>{nums1[c.first], nums2[c.second]});                   //**********
            if (c.second < n - 1)
                que.emplace(c.first, c.second + 1);
            k--;
        }
        return ans;
    }
};
