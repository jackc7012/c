#pragma once
#include "public.h"

// 1414
class Solution {
public:
    int findMinFibonacciNumbers(int k)
    {
        vector<int> fib{1, 1};
        int a = 1;
        int b = 1;
        while (a + b <= k) {
            fib.emplace_back(a + b);
            int tmp = a;
            a = b;
            b = tmp + b;
        }
        int result= 0;
        for (int i = fib.size() - 1; i >= 0 && k > 0;) {
            if (k < fib[i]) {
                --i;
            } else {
                k -= fib[i];
                ++result;
            }
        }
        return result;
    }
};