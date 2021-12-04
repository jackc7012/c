#pragma once
#include "public.h"

// 815
class Solution {
public:
    int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> tmp;
        unordered_set<int> visited;
        for (int i = 0; i < routes.size(); ++i) {
            for (int j = 0; j < routes[i].size(); ++j) {
                tmp[routes[i][j]].emplace_back(i);
            }
        }

        queue<int> qu;
        qu.push(source);
        int result = 0;
        while (!qu.empty()) {
            ++result;
            int sz = qu.size();
            for (int i = 0; i < sz; ++i) {
                auto a = qu.front();
                qu.pop();
                for (int j = 0; j < tmp[a].size(); ++j) {
                    if (find(visited.begin(), visited.end(), tmp[a][j]) == visited.end()) {
                        for (int k = 0; k < routes[tmp[a][j]].size(); ++k) {
                            if (routes[j][k] == target) {
                                return result;
                            }
                            qu.push(routes[j][k]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
