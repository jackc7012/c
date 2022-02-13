#pragma once
#include "public.h"

// 127 µ¥´Ê½ÓÁú£¨À§ÄÑ£©
// 33/50
class Solution {
public:
    int ladderLength(const string &beginWord, const string &endWord, const vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        queue<string> tmp;
        tmp.push(beginWord);
        set<string> visited;
        visited.insert(beginWord);

        int result = 1;
        while (!tmp.empty()) {
            int size = tmp.size();
            for (int i = 0; i < size; ++i) {
                auto res = tmp.front();
                tmp.pop();
                if (res == endWord) {
                    return result;
                }
                for (int j = 0; j < res.length(); ++j) {
                    for (int k = 0; k < 26; ++k) {
                        string temp = changeLetter(res, j, k);
                        if ((find(wordList.begin(), wordList.end(), temp) != wordList.end()) &&
                            (find(visited.begin(), visited.end(), temp) == visited.end())) {
                            tmp.push(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }
            ++result;
        }
        return 0;
    }

private:
    string changeLetter(const string& res, const int index, const int step) {
        string src(res);
        src[index] = 'a' + step;
        return src;
    }
};
