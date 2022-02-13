#pragma once
#include "public.h"

// 875 °®³ÔÏã½¶µÄçæçæ£¨ÖÐµÈ£©
class Solution {
public:
    int minEatingSpeed(const vector<int> piles, int h) {
        vector<int> tmp(piles);
        sort(tmp.begin(), tmp.end());
        int max = *max_element(piles.begin(), piles.end());
        int left = 1, right = max + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFinish(tmp, mid, h)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    bool canFinish(const vector<int> piles, int speed, int h) {
        int needTimes = 0;
        for (auto item : piles) {
            needTimes += ((item / speed) + ((item % speed == 0) ? 0 : 1));
        }
        return needTimes <= h;
    }
};
