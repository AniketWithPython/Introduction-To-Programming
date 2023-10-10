//print n lucas numbers, starts from 2 ,1 and then sum of previous 2 lucas numbers
//user inputs n

#include <stdio.h>

int main(){
	int a,b,c,n;
	a = 2;
	b = 1;		//initialisation with first 2 numbers
	
	printf("Enter the number of lucas numbers to print: ");
	scanf("%d", &n);
	
	switch(n){
		case 1:			//if n is 1 or 2
			printf("%d",a);
			break;
		case 2:
			printf("%d %d",a,b);
			break;
		default:		//for n >= 3
			printf("%d %d ",a,b);
			n -= 2;
			while (n > 0){
				c = a + b;
				a = b;
				b = c;
				printf("%d ", c);
				n--;
				}
		}
	puts("");
	return 0;
}
