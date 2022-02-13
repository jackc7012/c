#pragma once
#include "public.h"

// 1447 ���������еȣ�
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
    { // ŷ������㷨
        return b == 0 ? a : gcd(b, a % b);
    }
};