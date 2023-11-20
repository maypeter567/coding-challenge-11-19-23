//
// Created by Peter May on 2023-11-19.
//

#ifndef CODING_CHALLENGE_11_19_23_GAME_H
#define CODING_CHALLENGE_11_19_23_GAME_H

#include <iostream>
#include <vector>
#include "Printer.h"
#include "WordStorage.h"

using namespace std;

class Game{
public:
    Game(){};

    void setPlayerName(string setPlayerName) {
        this->playerName = setPlayerName;
    }

    bool guessLetter(char letter) {
        // implement
        return false;
    }

    bool guessWord(string word) {
        // implement
        return false;
    }

private:
    string playerName;
    int totalGuesses;
    int correctGuesses;
    int incorrectGuesses;
    vector<char> incorrectLetters;
    vector<char> correctLetters;
    vector<char> guessedWord;
    Printer printer;
    WordStorage wordStorage;
};

#endif //CODING_CHALLENGE_11_19_23_GAME_H
