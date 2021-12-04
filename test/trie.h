#pragma once
#include "public.h"

// 208
struct Tree {
    Tree *next[26] = {nullptr};
    bool isWord{false};
};

class Trie {
public:
    Trie() {
        root = new Tree();
    }

    void insert(string word) {
        Tree *location = root;
        for (int i = 0; i < word.length(); ++i) {
            if (location->next[word[i] - 'a'] == nullptr) {
                location->next[word[i] - 'a'] = new Tree();
            }
            location = location->next[word[i] - 'a'];
        }
        location->isWord = true;
    }

    bool search(string word) {
        Tree* location = root;
        for (int i = 0; i < word.length(); ++i) {
            if (location->next[word[i] - 'a'] != nullptr) {
                location = location->next[word[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return location && location->isWord;
    }

    bool startsWith(string prefix) {
        Tree* location = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (location->next[prefix[i] - 'a'] != nullptr) {
                location = location->next[prefix[i] - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }

private:
    Tree *root;
};
