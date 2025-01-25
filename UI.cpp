#pragma once
#include "UI.h"

UI::UI() { 
	for (int i = 0; i < 26; i++) {
		doneletters[i] = ' ';
	}
}


void UI::printStructure() {
	if (attempt == 0) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "             |\n             |\n             |\n             |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;
		;
	}
	else if (attempt == 1) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n             |\n             |\n             |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 2) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n             |\n             |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 3) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n             |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 4) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n      /      |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 5) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n      /|     |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 6) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n      /|\\    |\n             |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 7) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n      /|\\    |\n      /      |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
	else if (attempt == 8) {
		cout << "THEME: " << theme << endl << endl;
		cout << "+ ------------------ + \n";
		cout << "        HANGMAN" << endl;
		cout << "+ ------------------ + \n";
		cout << " \n";
		cout << "+ ------------- + \n";
		cout << "       |     |\n       |     |\n       O     |\n      /|\\    |\n      / \\    |\n";
		cout << "=====================\n\n";
		cout << endl << endl;

	}
}

void UI::printCurrentGems(int g) {
	cout << "Current Gems: " << g << "\t \t";
}

void UI::printAttemptsLeft() {
	cout << "Guesses Left: " << 8 - attempt << endl<<endl;
}

int UI::getletterindx(char letter) {
	for (int i = 0; i <= 25; i++) {
		if (Letters[i] == letter) {
			return i;
			break;
		}
	}
	return -1;
}

void UI::hideletter(char letter) {
	int hide = getletterindx(toupper(letter));
	Letters[hide] = ' ';
}

void UI::printLetters() {

	cout << endl << "------------------------------- -\n";
	cout << "Letters: \n";
	for (int i = 0; i <= 9; i++) {
		cout << Letters[i];
	}
	cout << endl;
	for (int i = 10; i <= 18; i++) {
		cout << Letters[i];
	}
	cout << endl;
	for (int i = 19; i <= 25; i++) {
		cout << Letters[i];
	}
	cout << endl << endl;
}


void UI::PrintWelcomeText(int g) {
	cout << "***********************************************" << endl;
	cout << "          WELCOME TO THE HANGMAN GAME!         " << endl;
	cout << "***********************************************" << endl;
	cout << endl;
	cout << "The rules are simple:" << endl;
	cout << "- Choose a theme from the options below." << endl;
	cout << "- A corresponding word will be generated." << endl;
	cout << "- Guess the word, letter by letter!" << endl;
	cout << "- You have 8 attempts to win." << endl;
	cout << endl;
	cout << "Gems System:" << endl;
	cout << "- Start with 4 gems." << endl;
	cout << "- Winning adds 2 gems." << endl;
	cout << "- Hints cost 4 gems (use wisely!)." << endl;
	cout << "- Current gems: " << g << endl;
	cout << endl;
	cout << " Tip: Start with commonly used letters for a better chance of success!" << endl;
	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Themes to Choose From:" << endl;
	cout << "1. Animals" << endl;
	cout << "2. Clothes" << endl;
	cout << "3. Food" << endl;
	cout << "4. Movies" << endl;
	cout << "5. Places" << endl;
	cout << "6. Sports" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "Ready to Play? Enter your theme below:" << endl;
	cout << "Theme: ";
}

void UI::IncrementAttempt() {
	attempt++;
}

bool UI::validateRepitition(char letter) {
	for (int i = 0; i < 26; i++) {
		if (doneletters[i] == letter) {
			
			return true;
			break;
		}
	}
	return false;
}

void UI::ClearTerminal() {
	cout << "\033[2J\033[1;1H";
}

bool UI::ValidateChar(char L) {
	if ((L >= 'A' && L <= 'Z') || (L >= 'a' && L <= 'z') || isdigit(L)) {
		if (cin.peek() == '\n') {
			return true;
		}
	}
	return false;
}

void UI::EditFormation(char L) {
	for (int i = 0; i < wordLength; i++) {
		if (word[i] == L) {
			formation[i] = L;
		}
	}
}



bool UI::Proceed(bool& win) {
	if (word == formation) {
		display("\n------------------------------- -\n");
		printFormation();
		display("\n\n------------------------------- -\n");
		cout << "Congratulations, you guessed the word!" << endl;
		win = true;
		return false;
	}
	else if (attempt >= 8) {
		printStructure();
		printFormation();
		display("\n------------------------------- -\n");
		cout << "You ran out of attempts!" << endl;
		cout << "The word was: " << word << endl;
		win = false;
		return false;
	}
	else return true;

}

void UI::setTheme(string t) { theme = t; }
void UI::setWord(string w) { word = w; }
void UI::setWordLength() {
	wordLength = word.length();

}

char UI::showLetter(int pos, int& g) {
	if (g >= 4) {
		if (pos <= wordLength) {
			if (formation[pos - 1] == '-') {
				g = g - 4;
				return word[pos - 1];
			}
			else {
				display("Letter already guessed by you!\n");
				return '@';
			}
		}
		else {
			display("Position exceeds the word length!");
			return '@';

		}
	}
	else {
		cout << "You do not have enough gems! Current gems:" << g << endl;
		return '@';

	}
}
void UI::setFormation() {
	formation = string(wordLength, '-');
}
string UI::getFormation() {
	return formation;
}
void UI::printFormation() {
	for (int i = 0; i < wordLength; i++) {
		cout << formation[i];
	}
}

void UI::addToDone(char let) {
	doneletters[done] = let;
	done++;
}
int UI::getAttempts() { return attempt; }


UI::~UI() {
	delete doneletters;
}