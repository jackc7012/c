#pragma once
#include "public.h"

// 815 ����·�ߣ����ѣ�
class Solution {
public:
    int numBusesToDestination(const vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
        unordered_map<int, vector<int>> tmp;
        unordered_set<int> visited;
        // ��·��Ӧ�Ĺ�����
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
                // tmp[a] ·��a�Ĺ���������
                for (const int &item : tmp[a]) {
                    if (find(visited.begin(), visited.end(), item) != visited.end()) {
                        continue;
                    }
                    for (int k = 0; k < routes[item].size(); ++k) {
                        if (routes[item][k] == target) {
                            return result;
                        }
                        qu.push(routes[item][k]);
                    }
                    visited.insert(item);
                }
            }
        }
        return -1;
    }
};
