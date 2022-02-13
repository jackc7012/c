#pragma once
#include "public.h"

// 797 所有可能的路径（中等）
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(const vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> tmp{0};
        dfs(graph, result, tmp, 0);
        return result;
    }

private:
    void dfs(const vector<vector<int>>& graph, vector<vector<int>>& result, vector<int>& tmp, const int index) {
        if (index == graph.size() - 1) {
            result.push_back(tmp);
            return ;
        }

        for (int i = 0; i < graph[index].size(); ++i) {
            tmp.push_back(graph[index][i]);
            dfs(graph, result, tmp, graph[index][i]);
            tmp.pop_back();
        }
    }
};

