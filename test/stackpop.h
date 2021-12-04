#pragma once
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty() && popV.empty()) {
            return true;
        }
        else if (pushV.size() != popV.size()){
            return false;
        }
        int index1 = 1;
        int index2 = 0;
        stack<int> temp;
        temp.push(pushV[0]);
        while (index2 < popV.size()) {
            if (!temp.empty() && temp.top() == popV[index2]) {
                temp.pop();
                ++index2;
            }
            else if (index1 < pushV.size()){
                temp.push(pushV[index1]);
                ++index1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};