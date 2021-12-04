#pragma once
#include <stack>
using namespace std;

class Solution {
public:
    void push(int value) {
        stack1.push(value);
        if (min_num.empty()) {
            min_num.push(value);
        }
        else {
            if (value < min_num.top()) {
                min_num.push(value);
            }
            else {
                min_num.push(min_num.top());
            }
        }
    }
    void pop() {
        if (!stack1.empty()) {
            stack1.pop();
            min_num.pop();
        }
    }
    int top() {
        if (!stack1.empty()) {
            return stack1.top();
        }
        return -1;
    }
    int min() {
        if (!min_num.empty()) {
            return min_num.top();
        }
        return -1;
    }

private:
    stack<int> stack1;
    stack<int> min_num;
};