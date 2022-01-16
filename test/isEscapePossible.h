#pragma once
#include "public.h"

// 1036
// 25/30
class Solution {
public:
    bool isEscapePossible(const vector<vector<int>>& blocked, const vector<int>& source, const vector<int>& target)
    {
        int size = blocked.size();
        if (size < 2) {
            return true;
        }
        int limit = size * (size - 1) / 2;
        int result = bfs(blocked, source, target, limit);
        if (result == -1) {
            return false;
        } else if (result == 1) {
            return true;
        } else if ((result == 0) && (bfs(blocked, target, source, limit) == 1)) {
            return true;
        } else {
            return false;
        }
    }

private:
    int bfs(const vector<vector<int>>& blocked, const vector<int>& source, const vector<int>& target, const int limit)
    {
        int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        set<pair<int, int>> visited;
        for (int i = 0; i < blocked.size(); ++i) {
            visited.insert(make_pair(blocked[i][0], blocked[i][1]));
        }
        queue<pair<int, int>> tmp;
        tmp.push(make_pair(source[0], source[1]));
        visited.insert(make_pair(source[0], source[1]));
        long long i = 0;
        while (!tmp.empty()) {
            int size = tmp.size();
            for (int i = 0; i < size; ++i) {
                auto s = tmp.front();
                tmp.pop();
                visited.insert(s);
                for (int j = 0; j < 4; ++j) {
                    if (i > limit) {
                        return 0;
                    }
                    int x = s.first + dir[j][0];
                    int y = s.second + dir[j][1];
                    if (x < 0 || y < 0 || x > 1000000 - 1 || y > 1000000 - 1 || visited.find(make_pair(x, y)) != visited.end()) {
                        continue;
                    }
                    if (x == target[0] && y == target[1]) {
                        return 1;
                    }
                    tmp.push(make_pair(x, y));
                    ++i;
                }
            }
        }
        return -1;
    }
};
