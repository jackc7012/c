#pragma once
#include "public.h"

// 648
struct Tree {
    Tree* next[26] = { nullptr };
    bool isWord{ false };
};

class Trie {
public:
    Trie() {
        root = new Tree();
    }

    void insert(string word) {
        Tree* location = root;
        for (int i = 0; i < word.length(); ++i) {
            if (location->next[word[i] - 'a'] == nullptr) {
                location->next[word[i] - 'a'] = new Tree();
            }
            location = location->next[word[i] - 'a'];
        }
        location->isWord = true;
    }

    string FindTrie(const string& src)
    {
        ostringstream ss;
        Tree* location = root;
        if (location->next[src[0] - 'a'] == nullptr) {
            return src;
        }
        for (int i = 0; i < src.length(); ++i) {
            if (location->next[src[i] - 'a'] != nullptr) {
                ss << src[i];
                location = location->next[src[i] - 'a'];
            }
            else {
                break;
            }
            if (location->isWord) {
                return ss.str();
            }
        }
        return location->isWord ? ss.str() : src;
    }

private:
    Tree* root;
};

class Solution {
public:
    string replaceWords(const vector<string>& dictionary, string sentence) {
        Trie t;
        string result;
        for (const auto& item : dictionary) {
            t.insert(item);
        }
        stringstream ss(sentence);
        string tmp;
        while (ss >> tmp) {
            string temp = t.FindTrie(tmp);
            result += temp + " ";
        }
        return result.substr(0, result.length() - 1);
    }
};