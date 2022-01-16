#pragma once
#include "public.h"

// 306
class Solution {
public:
    bool isAdditiveNumber(const string& num)
    {
        vector<string> nums;
        return dfs(num, 0, nums);
    }

private:
    bool dfs(const string& num, int index, vector<string>& nums)
    {
        if (index == num.size() && nums.size() < 3) {
            return false;
        }
        int size = nums.size();
        if (nums.size() >= 3 && nums[size - 1] != addStr(nums[size - 2], nums[size - 3])) {
            return false;
        } else if (nums.size() >= 3 && index == num.size()) {
            return true;
        }

        for (int i = index; i < num.size(); ++i) {
            string tmp = num.substr(index, i - index + 1);
            if (tmp.size() > 1 && tmp[0] == '0') {
                break;
            }
            nums.push_back(tmp);
            if (dfs(num, i + 1, nums)) {
                return true;
            }
            nums.pop_back();
        }
        return false;
    }

    string addStr(const string& strNum1, const string& strNum2)
    {
        string result;
        int a = strNum1.size();
        int b = strNum2.size();
        int carry = 0;
        while (a > 0 || b > 0 || carry > 0) {
            int num1 = ((a > 0) ? (strNum1[a - 1] - '0') : 0);
            int num2 = ((b > 0) ? (strNum2[b - 1] - '0') : 0);
            int c = num1 + num2 + carry;
            result += to_string(c % 10);
            carry = ((c >= 10) ? 1 : 0);
            --a;
            --b;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};