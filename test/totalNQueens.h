#pragma once
#include "public.h"

// 52N�ʺ�II�����ѣ�
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> temp(n, tmp);
        dfs(temp, 0);
        return result;
    }

private:
    void dfs(vector<vector<int>> &res, int row) {
        if (row == res.size()) {
            ++result;
            return;
        }

        for (int i = 0; i < res[0].size(); ++i) {
            if (!isValid(res, row, i)) {
                continue;
            }
            res[row][i] = 1;
            dfs(res, row + 1);
            res[row][i] = 0;
        }
    }

    bool isValid(const vector<vector<int>>& res, int row, int col) {
        // ����Ϸ����޻ʺ�
        for (int i = 0; i < row; ++i) {
            if (res[i][col] == 1) {
                return false;
            }
        }

        // ������Ϸ����޻ʺ�
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (res[i][j] == 1) {
                return false;
            }
        }

        // ������Ϸ����޻ʺ�
        for (int i = row - 1, j = col + 1; i >= 0 && j < res[0].size(); --i, ++j) {
            if (res[i][j] == 1) {
                return false;
            }
        }
    }

    int result{0};
};
