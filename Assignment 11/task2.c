//Memory match game
//use pointers to manipulate arrays

//user inputs grid size and the cards to flip

#include <stdio.h>
#include <stdlib.h>	//to use rand()
#include <time.h>

int size;		//declare size as global var

//functions written in order of invoking

void disp(int (*arr)[size][2], int n){		//display grid

	for (size_t i = 0; i < n; ++i){
	
		for (size_t j = 0; j < n; ++j){
		
			if ( *(*(*(arr+i)+j)+1) ){	//check the state of the card and print number or 'X' accordingly
				printf( "%5d", *(*(*(arr+i)+j)) );
			}
			
			else{
				printf("%5c", 'X');
			}
		}
		puts("");
	}

}

int win(int (*arr)[size][2], int n){		//return true if all cards are successfully flipped 
	
	for (size_t i = 0; i < n; ++i){
	
		for (size_t j = 0; j < n; ++j){
		
			if ( !(*(*(*(arr+i)+j)+1))  ){
				return 0;
			}
		}
	};
	
	return 1;

}

void flip(int (*arr)[size][2],int n){		//flip two cards and check if they match
	
	int a,b,c,d;
	
	puts("enter 2 cards to flip (row1 col1 row2 col2)");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	--a; --b; --c; --d;		//converting the row and column numbers to indices (e.g row 2 col 3 corresponds to indices 1 and 2 of matrix)
	
	*(*(*(arr+a)+b)+1) = 1;		//flipping the cards
	*(*(*(arr+c)+d)+1) = 1;
	
	disp(arr,n);
	
	if (!( *(*(*(arr+a)+b)) == *(*(*(arr+c)+d)) )){		//if not equal then setting the cards back to unflipped state
	
		*(*(*(arr+a)+b)+1) = 0;		
		*(*(*(arr+c)+d)+1) = 0;
		
	};
		

}

void game(){
	int card;
	srand(time(NULL));	//randomising rand()
	
	puts("Enter size of matrix (e.g 1 is 2x2, 2 is 4x4 and so on)");
	scanf("%d", &size);
	size *= 2;	//size must be even to ensure complete pairs are formed
	
	int cards[size][size][2];	//declaring 3d grid, the first 2 parameters are grid dimensions and the last parameter is an array containing the card number and state (1 -> flipped 0 -> unflipped
	int range = (size*size)/2;	//calculating the range of numbers on the cards
	int check[range+1];	
		
	for (size_t i = 0; i < range + 1; ++i){
		check[i] = 0;
	}
	
	for (size_t i = 0; i < size; ++i){
	
		for (size_t j = 0; j < size; ++j){
		
			card = rand() % range + 1; //get random card number 
			
			if (check[card] == 2){ //ensure that no more than 2 same cards are in the grid
				--j;
				continue;
			};
			
			cards[i][j][0] = card;
			cards[i][j][1] = 0;
			++check[card];
		}
	};
	
	disp(cards,size);	//display initial grid
	
	while(!(win(cards,size))){	//game loop
	
		flip(cards,size);
	};
	
	puts("You Won!");
		

}


void main(){
	
	int n;
	
	while (1){
	puts("Welcome to Memory match game");
	puts("flip 2 cards and if they match they get removed else they stay");
	puts("1. Start new game");
	puts("2. Exit");
	
	scanf("%d", &n);
	switch(n){
		case 1:
			game();
			break;
		case 2:
			puts("Exiting");
			return;
		default:
			puts("Invalid input");
		};	
	
	}
	

}


