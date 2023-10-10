//a game of bingo

#include <stdio.h>
#include <stdlib.h>	//to include rand() function
#include <time.h>


/* a1    b1    c1
   a2    b2    c2
   a3    b3    c3  */
   
int a1,a2,a3; 		//declaring global variables
int b1,b2,b3;
int c1,c2,c3;  
int l1,l2,l3,m1,m2,m3,n1,n2,n3;		//to store a copy of card values

void generate(){

	srand(time(NULL));
	
	a1 = rand() % 10 + 1;
	a2 = rand() % 10 + 1;
	a3 = rand() % 10 + 1;
	
	b1 = rand() % 10 + 11;
	b2 = rand() % 10 + 11;
	b3 = rand() % 10 + 11;
	
	c1 = rand() % 10 + 21;
	c2 = rand() % 10 + 21;
	c3 = rand() % 10 + 21;
	
	l1=a1;l2=a2;l3=a3;m1=b1;m2=b2;m3=b3;n1=c1;n2=c2;n3=c3;		//copying the values
	
}	

int call(){
	int n = rand() % 30 + 1;
	return n;
}

int main(){
	
	generate();
	
	printf("%7d%7d%7d\n%7d%7d%7d\n%7d%7d%7d\n\n",a1,b1,c1,a2,b2,c2,a3,b3,c3);	//print card
	
	while(!(a1==b2 && b2==c3 || a3==b2 && b2==c1 || a1==a2 && a2==a3 || b1==b2 && b2==b3 || c1==c2 && c2==c3 || a1==b1 && b1==c1 || a2==b2 && b2==c2 || a3==b3 && b3==c3)){
		
		int c = call();
		printf("callout: %d\n", c);
			
			//if callout found in board it sets it to 0
			if (c==l1)
				a1 = 0;
				
			if (c==l2)
				a2 = 0;
				
			if (c==l3)
				a3 = 0;
				
			if (c==m1)
				b1 = 0;
				
			if (c==m2)
				b2 = 0;
				
			if (c==m3)
				b3 = 0;
				
			if (c==n1)
				c1 = 0;
				
			if (c==n2)
				c2 = 0;
				
			if (c==n3)
				c3 = 0;
		
		printf("%7d%7d%7d\n%7d%7d%7d\n%7d%7d%7d\n\n",a1,b1,c1,a2,b2,c2,a3,b3,c3);
							
		
	}
	printf("\nBINGO!\n");
	
	return 0;
	
}
