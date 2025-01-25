#pragma once
#include <iostream>
#include <string>		//for strings
#include <cctype>		//for string comparisions 

using namespace std;
class UI
{
	string word="";
	string theme="";
	int wordLength=0;
	int attempt = 0;
	string formation="";
	char* doneletters=new char[26];
	int done = 0;
	char Letters[26] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M' };
public:
	UI();										//initialize done letters array
	void printStructure();						//prints hangman structure based on attempts left
	void printCurrentGems(int g);				//prints number of gems 
	void printAttemptsLeft();					//prints number of attempts left
	void printLetters();						//prints letter user could choose from (letters already guessed are hidden) 
	void printFormation();						//prints word user is trying to guess as dashes / letters 
	void PrintWelcomeText(int g);				//prints welcome page user sees at start up of game
	bool validateRepitition(char letter);		//returns true if letter already guessed, false if not
	void ClearTerminal();						//clears terminal between each guess so it looks more organized 
	bool ValidateChar(char L);					//makes sure character entered by user is either a letter or a position
	void EditFormation(char L);					//if guess is correct, this function is used to replace dash with correct letter
	bool Proceed(bool& win);					//returns false when game ends, true when game still in progress
	void setTheme(string t);					//sets theme as t
	void setWord(string w);						//sets word as w
	void setWordLength();						//sets wordlength based on word
	char showLetter(int pos, int& g);			//shows letter in word when user enters a position to be shown
	void setFormation();						//set formation as dashes that are equal to word length
	string getFormation();						//returns formation
	void addToDone(char let);					//if a letter is used add it to array of done letters
	int getAttempts();							//returns attempts
	int getletterindx(char letter);				//returns index of letter in Letters array
	void hideletter(char letter);				//to hide letter already guessed, it is replaced by empty character
	void IncrementAttempt();					//increases attempts by 1
	~UI();										//to delete dynamic array

	template <typename T>
	T readLine() {								//template function to read from terminal
		T input;
		cin >> input;
		return input;
	}

	template <typename T>
	void display(T output) {					//template function to write to function
		cout << output << endl;
	}
};
