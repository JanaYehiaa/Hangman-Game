#pragma once
#include <iostream>
#include <string>           //for string data type
#include <unordered_map>    //for themes and their corresponding words
#include <array>            //for corresponding words of themes stored in an array
#include <windows.h>        //for playing sounds
#include "UI.h"
using namespace std;

class HangmanGame
{
private: 
    int gems=4;
	string chosenTheme="";
    string randomWord="";
    array<string, 20> chosenArray;
    unordered_map<string, array<string, 20>> themes = {
        {"Animals", {"squirrel", "cheetah", "elephant", "horse", "rabbit", "zebra", "dolphin", "giraffe", "crocodile", "ostrich",
                     "penguin", "kangaroo", "platypus", "raccoon", "panther", "chameleon", "hyena", "toucan", "flamingo", "walrus"}},
        {"Clothes", {"jacket", "hoodie", "suit", "trenchcoat", "sweater", "boots", "scarf", "jeans", "sunglasses", "tights",
                     "blazer", "vest", "cardigan", "shorts", "hat", "cap", "gloves", "belt", "socks", "sandals"}},
        {"Food", {"apple", "banana", "burger", "pizza", "pasta", "watermelon", "strawberry", "blueberry", "raspberry", "apricot",
                  "chocolate", "icecream", "sandwich", "taco", "sushi", "omelette", "pancakes", "popcorn", "dumplings", "lasagna"}},
        {"Movies", {"titanic", "inception", "interstellar", "casablanca", "ladybird", "ratatouille", "annabelle", "matilda", "moonlight", "aquaman",
                    "avatar", "joker", "gladiator", "frozen", "coco", "shrek", "up", "zootopia", "parasite", "minions"}},
        {"Places", {"mauritania", "grenada", "turkey", "taiwan", "laos", "finland", "cyprus", "bhutan", "botswana", "belize",
                    "norway", "iceland", "malaysia", "jamaica", "peru", "zimbabwe", "canada", "germany", "france", "thailand"}},
        {"Sports", {"football", "basketball", "baseball", "soccer", "swimming", "rowing", "tennis", "cricket", "rugby", "volleyball",
                    "hockey", "badminton", "tabletennis", "cycling", "gymnastics", "skiing", "archery", "karate", "fencing", "surfing"}}
    };


public: 

	HangmanGame();                                      //seeds random number
    void StartGame(UI &ui);                             //handles start up of game
    bool EndGame(bool w, UI& ui);                       //handles end of game
    void PrintPlay(UI& ui);                             //prints play menu
    bool Play();                                        //handles game simulation
	void GenerateRandomWord(array<string, 20> arr);     //generates random word from array and sets it as word to be guessed by user
    void GetArray(string theme);                        //returns array of theme picked by user
    bool CorrectGuess(char g);                          //returns whether character entered by user is in the word 
};

