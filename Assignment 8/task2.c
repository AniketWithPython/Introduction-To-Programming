//word guessing game
//user inputs guesses

#include <stdio.h>

int main(){

    int attempts = 15,c = 0;	//c checks if word is already guessed or not
    char guess;
    const char secretWord[] = "programming";
    char str[12] = "-----------";

    printf("Welcome to word guessing game!\n");
    printf("You have %d attempts to guess the word!\n\n",attempts);

    for (int i = 0;i < 15; ++i){

        --attempts;

        printf("Enter character: ");
        scanf(" %c", &guess);

        for (size_t i = 0; i < 11; ++i){

            if (secretWord[i] == guess && str[i] == '-'){	//if '-' is not there means that the letter is already present
                str[i] = guess;					//this is done in case of repeated characters
                ++c;
                break;
            };
            
            

        };
        
        if (c == 11){						//if word guessed correctly
                printf("Congratulations! the word is %s\n",str);
                return 0;
	};
            
        printf("Current status: %s\n",str);			//display current status
        printf("You have %d attempts to guess the word!\n",attempts);	//display remaining attempts
    }

    printf("The Answer is: %s\n",secretWord);		//display answer if no more attempts left
    return 0;

}
