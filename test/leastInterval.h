#pragma once
#include "public.h"

// 621 任务调度器（中等）
class Solution {
public:
    int leastInterval(const vector<char>& tasks, int n)
    {
        int maxTasks[26] = {0};
        for (int i = 0; i < tasks.size(); ++i) {
            ++maxTasks[tasks[i] - 'A'];
        }
        int maxTask = 0;
        for (int i = 0; i < 26; ++i) {
            maxTask = max(maxTask, maxTasks[i]);
        }
        int result = (maxTask - 1) * (n + 1);
        for (int i = 0; i < 26; ++i) {
            if (maxTasks[i] == maxTask) {
                ++result;
            }
        }
        return max(result, tasks.size());
    }
};
