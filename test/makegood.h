#pragma once
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (!tmp.empty() && ((s[i] == tmp.top() + 32) || (s[i] == tmp.top() - 32))) {
                tmp.pop();
            }
            else {
                tmp.push(s[i]);
            }
        }
        string result;
        while (!tmp.empty()) {
            result += tmp.top();
            tmp.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};