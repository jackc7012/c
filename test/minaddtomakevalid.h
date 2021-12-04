#pragma once
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> temp;
        for (int i = 0; i < s.size(); ++i) {
            if (!temp.empty() && s[i] == ')' && temp.top() == '(') {
                temp.pop();
            }
            else {
                temp.push(s[i]);
            }
        }
        return temp.size();
    }
};