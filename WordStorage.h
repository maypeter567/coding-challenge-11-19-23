//
// Created by Peter May on 2023-11-19.
//

#ifndef CODING_CHALLENGE_11_19_23_WORDSTORAGE_H
#define CODING_CHALLENGE_11_19_23_WORDSTORAGE_H

#include <iostream>

using namespace std;

class WordStorage{
public:
    WordStorage(){}

    void setWord(string setWord) {
        for (char c : setWord) {
            this->word.push_back(c);
        }
    }

    vector<int> hasLetter(char letter) {
        vector<int> indexes;
        for (char c : word) {
            if (c == letter) {
                indexes.push_back(c);
            }
        }
        return indexes;
    }

    bool isWord(string guessWord) {
        // implement
        return false;
    }

private:
    vector<char> word;
};

#endif //CODING_CHALLENGE_11_19_23_WORDSTORAGE_H
