//
// Created by Peter May on 2023-11-19.
//

#ifndef CODING_CHALLENGE_11_19_23_GAME_H
#define CODING_CHALLENGE_11_19_23_GAME_H

#include <iostream>
#include <vector>
#include <unistd.h>
#include <time.h>
#include "Printer.h"
#include "WordStorage.h"

using namespace std;

class Game{
public:
    Game() {
        playerName = "";
        totalGuesses = 0;
        correctGuesses = 0;
        incorrectGuesses = 0;
        wordLength = 0;

        preChosenWords.push_back("science");
        preChosenWords.push_back("apples");
        preChosenWords.push_back("photosynthesis");
        preChosenWords.push_back("car");
        preChosenWords.push_back("democracy");
        preChosenWords.push_back("canadians");
        preChosenWords.push_back("dragon");
        preChosenWords.push_back("axles");
        preChosenWords.push_back("cartoon");
        preChosenWords.push_back("jazz");
    }

    void setPlayerName() {
        getline(cin, playerName);
    }

    bool guessLetter(char letter) {
        vector<int> indexes = wordStorage.hasLetter(letter);
        if (indexes.empty()) {
            wrongGuess(letter);
            return false;
        }
        correctGuess(letter, indexes);
        return true;
    }

    bool guessWord(string word) {
        if (wordStorage.isWord(word)) {
            totalGuesses++;
            correctGuesses++;
            return true;
        } else {
            totalGuesses += 2;
            incorrectGuesses += 2;
            return false;
        }
    }

    void run() {
        cout << "Welcome to Hang Man! the classic luck based game of 'can you guess that letter?'\n" << endl;
        unsigned int microsecond = 1000000;
        usleep(2 * microsecond);
        cout << "lets start with your name, please insert it here and press enter: ";

        setPlayerName();

        cout << "\nnice to meet you " << playerName << ", please enjoy the game! but here are the rules first.\n" << endl;

        cout << "1. you can only guess a word if you type it's full length." << endl;
        cout << "2. incorrect word guesses don't reveal letters and count as two failed guesses." << endl;
        cout << "3. have fun!" << endl;
        string answer;

        while (answer != "y") {
            cout << "\nare you ready to begin? y/n: ";
            getline(cin, answer);
            if (answer == "y") {
                playGame();
            } else {
                cout << "if you would like to quit, type 'quit' or 'y' now: ";
                getline(cin, answer);
                if (answer == "quit") {
                    break;
                }
            }
        }
    }

private:
    void playGame() {
        if (preChosenWords.size() != 0) {
            unsigned int microsecond = 1000000;
            setUpHiddenWord();

            setUpGuessedWord();

            cout << "the length of your word is " << to_string(wordLength) << ". happy guessing!\n" << endl;

            bool play = true;
            bool firstRound = true;

            while (play) {
                if (!firstRound) {
                    cout << "total guesses = " << to_string(totalGuesses) << endl;
                    cout << "total correct guesses = " << to_string(correctGuesses) << endl;
                    cout << "total incorrect guesses = " << to_string(incorrectGuesses) << endl;
                    sort(correctLetters.begin(), correctLetters.end());
                    string toPrint;
                    for (auto c: correctLetters) {
                        toPrint.push_back(c);
                        toPrint += ", ";
                    }
                    if (!toPrint.empty()) {
                        toPrint.erase(toPrint.length() - 2);
                    }
                    cout << "all correct letters: " << toPrint << endl;
                    toPrint = "";
                    for (auto c: incorrectLetters) {
                        toPrint.push_back(c);
                        toPrint += ", ";
                    }
                    if (!toPrint.empty()) {
                        toPrint.erase(toPrint.length() - 2);
                    }
                    cout << "all incorrect letters: " << toPrint << endl;
                } else {
                    firstRound = false;
                }

                cout
                        << "please enter a single character to guess, or a word if you think you know what it is. press enter after your guess.\n\nguess: ";
                string guess;
                getline(cin, guess);
                if (guess.length() == 1) {
                    if (guessLetter(guess[0])) {
                        if (wordCompleted()) {
                            cout << "you found the word " << playerName << "! here are your results!\n" << endl;
                            cout << "total guesses = " << to_string(totalGuesses) << endl;
                            cout << "total correct guesses = " << to_string(correctGuesses) << endl;
                            cout << "total incorrect guesses = " << to_string(incorrectGuesses) << endl;
                            cout << printGuessedWord() << "\n\nwould you like to play again? y/n: ";
                            string response;
                            while (true) {
                                getline(cin, response);
                                if (response == "y") {
                                    playGame();
                                    play = false;
                                    break;
                                } else if (response == "n") {
                                    cout << "\n\nthanks for playing " << playerName << "! till next time.";
                                    play = false;
                                    break;
                                }
                            }
                            continue;
                        } else {
                            cout << "good guess " << playerName << "! you have found " << printGuessedWord() << endl;
                        }
                    } else {
                        cout << "incorrect guess, you have found " << printGuessedWord() << endl;
                    }
                } else if (guess.length() != wordLength) {
                    cout << "the word you guessed was not the correct length, it has to be " << to_string(wordLength)
                         << " characters long." << endl;
                    usleep(2 * microsecond);
                    continue;
                } else if (guessWord(guess)) {
                    cout << "you found the word" << playerName << "! here are your results!\n" << endl;
                    cout << "total guesses = " << to_string(totalGuesses) << endl;
                    cout << "total correct guesses = " << to_string(correctGuesses) << endl;
                    cout << "total incorrect guesses = " << to_string(incorrectGuesses) << endl;
                    cout << printGuessedWord() << "\n\nwould you like to play again? y/n: ";
                    string response;
                    while (true) {
                        getline(cin, response);
                        if (response == "y") {
                            reset();
                            playGame();
                            play = false;
                            break;
                        } else if (response == "n") {
                            cout << "\n\nthanks for playing " << playerName << "! till next time.";
                            play = false;
                            break;
                        }
                    }
                    continue;
                } else {
                    cout << "incorrect guess, you still have " << printGuessedWord() << endl;
                }
            }
        } else {
            cout << "you have completed all the prebuilt words, thanks for playing " << playerName << "!" << endl;
            usleep(2 * 1000000);
        }
    }

    void wrongGuess(char letter) {
        totalGuesses++;
        incorrectGuesses++;
        incorrectLetters.push_back(letter);
    }

    void correctGuess(char letter, vector<int>& indexes) {
        for (int i : indexes) {
            guessedWord[i] = letter;
        }
        correctGuesses++;
        correctLetters.push_back(letter);
    }

    string printGuessedWord() {
        string toReturn = "";
        for (auto c : guessedWord) {
            toReturn += c;
        }
        return toReturn;
    }

    bool wordCompleted() {
        for (auto c : guessedWord) {
            if (c == '~') {
                return false;
            }
        }
        return true;
    }

    void setUpGuessedWord() {
        guessedWord.clear();
        int i = 0;
        while (i < wordLength) {
            guessedWord.push_back('~');
            i++;
        }
    }

    void setUpHiddenWord() {
        srand(time(0));
        int random_integer = rand() % preChosenWords.size();
        wordLength = preChosenWords[random_integer].size();
        wordStorage.setWord(preChosenWords[random_integer]);
        int i = 0;
        for (auto c = preChosenWords.begin(); c < preChosenWords.end(); c++) {
            if (i == random_integer) {
                preChosenWords.erase(c);
                break;
            }
            i++;
        }
    }

    void reset() {
        totalGuesses = 0;
        correctGuesses = 0;
        incorrectGuesses = 0;
        incorrectLetters.clear();
        correctLetters.clear();
        guessedWord.clear();
    }

    string playerName;

    int totalGuesses;
    int correctGuesses;
    int incorrectGuesses;
    int wordLength;

    vector<char> incorrectLetters;
    vector<char> correctLetters;
    vector<char> guessedWord;

    Printer printer;
    WordStorage wordStorage;

    vector<string> preChosenWords;
};

#endif //CODING_CHALLENGE_11_19_23_GAME_H
