# coding-challenge-11-19-23
This is a coding challenge for BYU OIT

## Planning
### inputs
when this program is called, it will ask the player to input their name, which will be used to give feedback on their choices. the game will give a string explaining the rules, which include making single letter guesses, an optional hard mode if implemented, and making full word guesses with drawbacks. if the user wishes to end the game early they can type "quit()" to exit the program.
to execute the program, simply call it in the command line and the game will begin. No program arguments are required.

### structure
all classes:
- WordStorage: stores the word and checks if a guess is inside the word.
- Game: stores the guesses and ensures no repeats.
- Printer: prints the hangman based on the number of guesses. optional if time permits.

### functions
#### WordStorage
- setWord: takes a string as an input and stores it in a vector
- hasLetter: returns an array of indexes for the letter in the word
- isWord: returns true or false if the word stored is the string passed in

#### Game
- run: void function that loops through the game and calls the functions while interacting with the classes.
- setPlayerName: a void function that calls getline for the user to input their name when the program starts up.
- guessLetter: takes any inputs from the user and passes it into WordStorage
- guessWord: -optional- if time permits, allow the player to guess the word. counts as two incorrect guesses and doesn't reveal letters if incorrect
- wrongGuess: increments incorrectGuesses and totalGuesses while storing the wrong guess in incorrectLetters
- correctGuess: increments correctGuesses and totalGuesses while storing the correct guess in correctLetters. The function also updates guessed word with the letter guessed.

#### Printer
- printHangMan: prints the hang man based on how many incorrect guesses are passed in

### variables
#### WordStorage
- word: a vector of all the chars for the word

#### Game
- playerName: a string of the players name
- totalGuesses: an int that represents the number of guesses made
- correctGuesses: an int that represents the number of correct guesses
- incorrectGuesses: an int that represents the number of incorrect guesses
- incorrectLetters: a sorted vector of incorrectly guessed chars
- correctLetters: a sorted vector of correctly guessed chars
- guessedWord: a vector of chars containing the guessed letters in position. un-guessed words contain the '~' char

- printer: the Printer class object stored in Game
- wordStorage: the WordStorage class object stored in Game

#### Printer
- no variables