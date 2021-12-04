#pragma once
#include "public.h"

struct Record {
    string name_;
    string date_;
    int time_;
    Record(const string &name, const string &date, int time)
        : name_(name), date_(date), time_(time)
    {}
};

struct CarInfo {
    string name_; // 车牌
    int times_;   // 时长
    int time_;    // 次数
    CarInfo(const string& name, int times, int time)
        : name_(name), times_(times), time_(time)
    {}
};

class Solution {
public:
    vector<string> minTop5(int month, vector<Record> const& carInfo) {
        vector<string> result;
        map<string, pair<int, int>> tmp; // 车牌 次数 时长
        for (const auto& item : carInfo) {
            string date = item.date_.substr(5, 2);
            if (atoi(date.c_str()) != month) {
                continue;
            }
            int times = 1;
            int time = item.time_;
            if (tmp.find(item.name_) != tmp.end()) {
                times += tmp[item.name_].first;
                time += tmp[item.name_].second;
            }
            tmp[item.name_] = make_pair(times, time);
        }
        vector<pair<string, pair<int, int>>> temp(tmp.begin(), tmp.end());
        sort(temp.begin(), temp.end(), [](pair<string, pair<int, int>> &a1, pair<string, pair<int, int>>& a2){
            if (a1.second.second != a2.second.second)
                return a1.second.second > a2.second.second;
            else if (a1.second.second == a2.second.second && a1.second.first != a2.second.first)
                return a1.second.first > a2.second.first;
            else
                return a1.first < a2.first;
        });
        for (int i = 0; i < (temp.size() >= 5 ? 5 : temp.size()); ++i) {
            result.emplace_back(temp[i].first);
        }
        return result;
    }

};