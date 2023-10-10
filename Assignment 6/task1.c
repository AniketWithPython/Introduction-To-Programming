//menu driven program to simulate a bank account
//user inputs task to perform and the corresponding required values

#include <stdio.h>

float balance = 1000.0;		//store balance globally
int transactionCount = 0;	//store transaction count globally

void deposit(float amt){	//deposit amount to balance

	balance += amt;
	transactionCount++;
	
	}
	
void withdraw(float amt){	//withdraw amount to balance

	if( balance - amt < 0){ //to prevent negative balance
		puts("You cannot withdraw more than deposit!");
		return;
	}
	balance -= amt;
	transactionCount++;
	
}
	
void displayBalance(){		//display balance

	printf("your balance is: %f\n\n",balance);
}

void displayTransactionCount(){	//display no. of transactions

	printf("Your Transaction count is: %d\n\n", transactionCount);
}

int main(){		

	puts("Bank Account Simulation");
	puts("------------------------");
	puts("");
	
	int opt;	//store option
	float input;	//store input amount
	
	while (opt != 5){	//opt = 5 will lead to program termination
	
		puts("1. Deposit");
		puts("2. Withdraw");
		puts("3. Display Balance");
		puts("4. Display Transaction Count");
		puts("5. Quit");
		puts("");
		
		printf("Enter your choice: ");
		scanf("%d", &opt);
		puts("");
		
		switch(opt){
		
			case 1:	//deposit
		
				printf("Enter amount to deposit: ");
				scanf("%f", &input);
				deposit(input);
				break;
		
			case 2:	//withdraw
			
				printf("Enter amount to withdraw: ");
				scanf("%f", &input);
				withdraw(input);
				break;
			
			case 3:	//display balance
			
				displayBalance();
				break;
			
			case 4:	//display transaction count
			
				displayTransactionCount();
				break;
				
			default: //display exit message
				
				puts("Exiting the Program. Thank You!");
		}
	}
	
	return 0;
	
}













