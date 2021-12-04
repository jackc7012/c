#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size() == 0) {
            return false;
        }
        bool flag = TraceBack(sequence, 0, sequence.size() - 1);
        return flag;    
    }

private:
    bool TraceBack(const vector<int>& sequence, const int begin, const int end) {
        if (begin >= end) {
            return true;
        }
        int mid = begin;
        for (; mid < end && sequence[mid] < sequence[end]; ++mid);
        for (int i = mid; i < end; ++i) {
            if (sequence[i] < sequence[end]) {
                return false;
            }
        }

        return TraceBack(sequence, begin, mid - 1) && TraceBack(sequence, mid, end - 1);
    }
};