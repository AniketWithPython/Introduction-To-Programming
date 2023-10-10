//to calculate the difference in the first and last digits of an integer n
//user inputs n

#include <stdio.h>

int main(){
	long int n;
	int a,b;	//first and last digits
	
	printf("Enter the integer: ");
	scanf("%ld", &n);
	
	b = n % 10;	//gets the last digit e.g 123 % 10 = 3
	
	while (n>=10) n /= 10;		//reduces the integer to the first digit e.g 123 -> 1
	
	a = n;			//assigns digit to a
	
	printf("\nDifference is %d\n", a - b);
	
	return 0;
}

