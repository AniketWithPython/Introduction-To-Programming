//number guessing game
//create functions getGuess() and evaluateGuess()
//user inputs lower bound and upper bound and the guesses

#include <stdio.h>
#include <stdlib.h>	//to include rand() function
int count = 1;		//counter


int getGuess(){		//get guess of user

	int guess;
	printf("Enter your guess!: ");
	scanf("%d", &guess);
	puts("");
	return guess;
	
}

void evaluateGuess(int guess, int target){		//evaluate the guess

	if (guess == target){
		printf("Congratulations!\n");
		printf("no. of guesses: %d\n", count);
		return;
	}
	
	else if (guess < target){
		printf("Too Low!, Try again!\n");
		count++;
		evaluateGuess( getGuess(), target);	//return control to evaluateGuess()
	}
	
	else {
		printf("Too High!, Try again!\n");
		count++;
		evaluateGuess( getGuess(), target);	//return control to evaluateGuess()
		}
}

int main(){

	int ub, lb;
	
	printf("Welcome to a number guessing game!\n");
	printf("Enter the lower and upper bounds seperated by a space: ");
	scanf("%d %d", &lb, &ub);
	puts("");
	
	while (lb >= ub){	//if wrong limits entered
		printf("Please enter proper limits: ");
		scanf("%d %d", &lb, &ub);	
		puts("");
		}
	
	int target = rand() % (ub - lb + 1) + lb;	//scale rand() output to a value within the range incl of ub and lb
	
	evaluateGuess( getGuess(), target );		//pass control to evaluateGuess()
	
	return 0;
	
}
