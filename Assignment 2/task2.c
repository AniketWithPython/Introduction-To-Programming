//find and print largest prime palindrome within given range
//user inputs range
//use "-lm" argument while compiling 

#include <stdio.h>
#include <math.h>

int main () {
	int range,num,test,e,temp,c;	//range -> input for range, num -> number, test -> number being tested, e -> exponent, temp -> temporary, c -> counter, 
	int try,win;			//try -> contitional output, win -> winner
	num = 1;		//set initial number to 1
	printf( "Enter a range in which to check (starts from 1): " );
	scanf( "%d", &range);
	while (num <= range) {
		test=num;
		try=1;
		e=-1;
		while (test>0) {
			test /= 10;
			e++;
			}
		temp=0;
		test=num;
		while (e>=0) {		//check for palindrome
			temp += (test%10)*pow(10,e);
			e--;
			test /= 10;
			}
		if (temp==num) {	//check for prime
			c=2;
			while (c<num) {
				if ( num % c == 0) {
					try=0;
					break;
					};
				c++;
					}
				}
		else {		//if it is not prime
			num++;
			continue;
			}
		if (try==0) {	//if fails both conditions
			num++;
			continue;
			}
		
		win=num;	//if both conditions work we have a winner :)
		num++;
		}
	printf("the number is %d\n", win);
	return 0;
	}
				

