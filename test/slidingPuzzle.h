#pragma once
#include "public.h"

// 773
class Solution {
public:
    int slidingPuzzle(const vector<vector<int>>& board) {
        string src;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                src += board[i][j] + '0';
            }
        }
        string target("123450");
        queue<string> tmp;
        tmp.push(src);
        unordered_set<string> visited;
        visited.insert(src);

        int result = 0;
        while (!tmp.empty()) {
            int sz = tmp.size();
            for (int i = 0; i < sz; ++i) {
                string a = tmp.front();
                tmp.pop();
                if (a == target) {
                    return result;
                }
                int index = findZeroIndex(a);
                if (index == -1) {
                    continue;
                }
                for (int j = 0; j < boardMap[index].size(); ++j) {
                    string temp(a);
                    swap(temp[index], temp[boardMap[index][j]]);
                    if (find(visited.begin(), visited.end(), temp) == visited.end()) {
                        tmp.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            ++result;
        }
        return -1;
    }

private:
    int findZeroIndex(const string &src) {
        for (int i = 0; i < src.size(); ++i) {
            if (src[i] == '0') {
                return i;
            }
        }
        return -1;
    }

    vector<vector<int>> boardMap{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
};
