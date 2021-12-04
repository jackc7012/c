#pragma once
#include "public.h"

// 210
class Solution {
public:
    vector<int> findOrder(int numCourses, const vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> visited(numCourses, 0);
        for (const auto &item : prerequisites) {
            edges[item[1]].emplace_back(item[0]);
        }
        for (int i = 0; i < edges.size(); ++i) {
            bool flag = true;
            if (visited[i] == 0) {
                flag = dfs(edges, visited, i);
            }
            if (!flag) {
                return {};
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool dfs(const vector<vector<int>> &edges, vector<int> &visited, int index) {
        visited[index] = 1;
        for (auto item : edges[index]) {
            if (visited[item] == 0) {
                bool flag = dfs(edges, visited, item);
                if (!flag) {
                    return false;
                }
            }
            else if (visited[item] == 1) {
                return false;
            }
        }
        result.emplace_back(index);
        return true;
    }

    vector<int> result;
};
