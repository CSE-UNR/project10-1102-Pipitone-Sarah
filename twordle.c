//Sarah Pipitone
//04/20/2026
//Project 10: Knock-off Wordle

#include <stdio.h>
#define FILENAME "mystery.txt"
#define CAP 100

void getSecretWord(char secretWord[]);

void pointAtCorrectLetters(char secretWord[], char guessedWord[]);

void capitolizeCorrectPositions(char secretWord[], char guessedWord[]);

int checkForWin(char secretWord[], char guessedWord[]);

void displayWinScreen(char secretWord[], int* guesses);

int main(){
	char guessedWord[CAP];
	char secretWord[CAP];
	getSecretWord(secretWord);
	int guesses = 0;
	for(int g = 1; g < 7; g++){
		guesses++;
		if(g < 6){
			printf("GUESS %d! Enter your guess: ", g);
		}
		else if(g == 6){
			printf("FINAL GUESS: ");
		}
		fgets(guessedWord, CAP, stdin);
		printf("================================");
		printf("\n");
		checkForWin(secretWord, guessedWord);
		int win = checkForWin(secretWord, guessedWord);
		if(win == 1){
			for(int k = 0; k < 5; k++){
				guessedWord[k] = guessedWord[k] - 32;
			}
			printf("%s", guessedWord);
			displayWinScreen(secretWord, &guesses);
			return 0;
		}
		else if(win == 0){
		capitolizeCorrectPositions(secretWord, guessedWord);
		pointAtCorrectLetters(secretWord, guessedWord);
		printf("\n");
		}
	}
	printf("You lost, better luck next time!\n");
	return 0;
}


void getSecretWord(char secretWord[]){
	FILE* secretWordPtr;
	secretWordPtr = fopen(FILENAME, "r");
	int count = 0;
	char letter;
	while(fscanf(secretWordPtr, " %c", &letter) == 1){
		secretWord[count] = letter;
		count++;
	}
	fclose(secretWordPtr);
}

void pointAtCorrectLetters(char secretWord[], char guessedWord[]){
	char pointString[CAP];
	for(int k = 0; k < 5; k++){
		for(int j = 0; j < 5; j++){
			if(guessedWord[k] == secretWord[j]){
				pointString[k] = '^';
				break;
			}
			else if(j == 4){
				pointString[k] = ' ';
			}
		}	
	}
	for(int i = 0; i < 5; i ++){
		printf("%c", pointString[i]);
	}
}

void capitolizeCorrectPositions(char secretWord[], char guessedWord[]){
	for(int k = 0; k < 5; k++){
		if(guessedWord[k] == secretWord[k]){
			guessedWord[k] = guessedWord[k] - 32;
		}
	}
	printf("%s", guessedWord);
}

int checkForWin(char secretWord[], char guessedWord[]){
	int winner = 0;
	if(guessedWord[0] == secretWord[0] && guessedWord[1] == secretWord[1] && guessedWord[2] == secretWord[2] && guessedWord[3] == secretWord[3] && guessedWord[4] == secretWord[4]){
		winner = 1;	
	}
	else{
		winner = 0;
	}
	return(winner);
}

void displayWinScreen(char secretWord[], int* guesses){
	switch(*guesses){
		case 1:
			printf("\nYou won in 1 guess!\nGOATED!\n");
			break;
		case 2:
		case 3:
			printf("\nYou won in %d guesses!\nAmazing!\n", *guesses);
			break;
		case 4:
		case 5:
			printf("\nYou won in %d guesses!\nNice!\n", *guesses);
			break;
		case 6:
			printf("\nYou won in 6 guesses!\n");
	}
}
