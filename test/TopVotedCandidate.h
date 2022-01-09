#pragma once
#include "public.h"

// 911
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
    {
        for (int i = 0; i < persons.size(); ++i) {
            timeToPersons[times[i]] = persons[i];
        }
    }

    int q(int t)
    {
        int *times = new int[timeToPersons.size()];
        memset(time, 0, timeToPersons.size());
        for (const auto& item : timeToPersons) {
            if (item.first > t) {
                break;
            }
        }
        delete []times;
    }

private:
    map<int, int> timeToPersons;
};
