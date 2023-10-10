//calculate factorial of an integer
//user inputs integer

#include <stdio.h>

int main(){
	int n;		//declaration, n -> user input, result -> final result
	long double result = 1;
	
	printf("Enter integer to calculate factorial: ");	//prompt
	scanf("%d", &n);		//input
	
	while (n > 0) {		//calculate factorial
		result*=n;
		n--;
	}
	
	printf("Your answer is: %.0Lf\n", result);		//display result
	return 0;
}
