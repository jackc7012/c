#pragma once
#include "public.h"

// 1996
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int>& a1, vector<int>& a2){
            return ((a1[0] == a2[0]) ? (a1[1] < a2[1]) : (a1[0] > a2[0]));
        });
        int max_def = 0;
        int result = 0;
        for (const auto& a : properties) {
            if (a[1] < max_def) {
                ++result;
            } else {
                max_def = a[1];
            }
        }
        return result;
    }
};
