//
// Created by Peter May on 2023-11-19.
//

#ifndef CODING_CHALLENGE_11_19_23_WORDSTORAGE_H
#define CODING_CHALLENGE_11_19_23_WORDSTORAGE_H

#include <iostream>

using namespace std;

class WordStorage{
public:
    WordStorage(){
        word = "";
    }

    void setWord(string setWord) {
        word.clear();
        for (char c : setWord) {
            this->word.push_back(c);
        }
    }

    vector<int> hasLetter(char letter) {
        vector<int> indexes;
        int i = 0;
        for (char c : word) {
            if (c == letter) {
                indexes.push_back(i);
            }
            i++;
        }
        return indexes;
    }

    bool isWord(string guessWord) {
        return guessWord == word;
    }

private:
    vector<char> wordVector;
    string word;
};

#endif //CODING_CHALLENGE_11_19_23_WORDSTORAGE_H
