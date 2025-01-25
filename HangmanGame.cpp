#pragma once
#include "HangmanGame.h"
HangmanGame::HangmanGame() {
	srand((int)time(NULL));
}

void HangmanGame::GetArray(string theme) {
	chosenArray = themes[theme];  
	
}

void HangmanGame::GenerateRandomWord(array<string, 20> arr) {
	int randomNum = rand() % 20; 
	randomWord = arr[randomNum];
}

bool HangmanGame::CorrectGuess(char g) {
	return randomWord.find((char)tolower(g)) != string::npos;

}


void HangmanGame::StartGame(UI & ui) {
	ui.PrintWelcomeText(gems);
	chosenTheme = ui.readLine<string>();
	while (themes.find(chosenTheme) == themes.end()) {
		ui.display<string>("Invalid Theme! Please choose one from above! Be careful, capitalization matters.");
		chosenTheme = ui.readLine<string>();
	}
	GetArray(chosenTheme);
	GenerateRandomWord(chosenArray);
	ui.setTheme(chosenTheme);
	ui.setWord(randomWord);
	ui.setWordLength();
	ui.setFormation();
	ui.display("-----------------------------------------------------------------------------------------------------");
}

bool HangmanGame::EndGame(bool w, UI& ui) {
	if (w) {
		gems = gems + 2;
		PlaySound(TEXT("win.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	else {
		PlaySound(TEXT("lose.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	ui.display("Do you want to play another round? [y/n]");
	char r = ui.readLine<char>();
	while (r != 'y' && r != 'n') {
		ui.display("Couldn't understand response, try again! ");
		r = ui.readLine<char>();
	}
	if (r == 'y') return true;
	else if (r == 'n') return false;

}

void HangmanGame::PrintPlay(UI& ui) {
	ui.printCurrentGems(gems);
	ui.printAttemptsLeft();
	ui.printStructure();
	ui.printFormation();
	ui.printLetters();
}

bool HangmanGame::Play() {
	bool w = true;
	UI ui;
	StartGame(ui); //initializes word and theme in both ui and hangman
	ui.ClearTerminal();

	while (ui.Proceed(w)) {
		PrintPlay(ui);
		ui.display("Please enter a letter! \n");
	    ui.display("Type the position of the letter to show for 4 gems\n");
		char c = ui.readLine<char>();
		c = tolower(c);

		if (ui.ValidateChar(c)) {
			if (!isdigit(c) && !ui.validateRepitition(c)) { 
				ui.hideletter(c); 
				ui.addToDone(c);
				if (CorrectGuess(c)) { ui.EditFormation(c); }
				else {
					ui.IncrementAttempt(); //guess was wrong and in next iteration hangman will add an attempt
					PlaySound(TEXT("soundeffect.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
			}
			else if(isdigit(c)){ 
				int pos = c - '0';
				char hint = ui.showLetter(pos, gems);
				ui.EditFormation(hint);
			}
			else { 
				ui.display("Letter already guessed before! ");
			}
		}
		else {
			ui.display("Please enter a valid character, or a position index to continue playig!");
		}
		ui.ClearTerminal();

	}

	return EndGame(w, ui);
	
}