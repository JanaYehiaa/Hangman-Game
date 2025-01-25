#include "HangmanGame.h"

int main() {
	HangmanGame h;
	
	bool play = true;
	while (play) {
		play = h.Play(); //continues game as long as play function is true
	}
	return 0;
}