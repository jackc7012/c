#pragma once
#include "public.h"

// 1447 最简分数（中等）
class Solution {
public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> result;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (gcd(i, j) == 1) {
                    string tmp;
                    tmp += to_string(j) + "/" + to_string(i);
                    result.emplace_back(tmp);
                }
            }
        }
        return result;
    }

private:
    int gcd(int a, int b)
    { // 欧几里得算法
        return b == 0 ? a : gcd(b, a % b);
    }
};