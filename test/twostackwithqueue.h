#pragma once
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int result = -1;
        while (stack1.size() != 1) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        result = stack1.top();
        stack1.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};