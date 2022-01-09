#pragma once
#include "public.h"

// 807
class Solution {
public:
    char slowestKey(const vector<int>& releaseTimes, const string& keysPressed)
    {
        map<char, int> tmp;
        char key = keysPressed[0];
        tmp[keysPressed[0]] = releaseTimes[0];
        for (int i = 1; i < keysPressed.length(); ++i) {
            if (!tmp.count(keysPressed[i])) {
                tmp[keysPressed[i]] = releaseTimes[i] - releaseTimes[i - 1];
            } else {
                tmp[keysPressed[i]] += releaseTimes[i] - releaseTimes[i - 1];
            }
            if (tmp[key] < tmp[keysPressed[i]] ||
                (tmp[key] == tmp[keysPressed[i]] && key < keysPressed[i])) {
                key = keysPressed[i];
            }
        }
        return key;
    }
};