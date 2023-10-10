//to find the name, shape and perimeter of a given polygon
//user inputs number of sides

#include <stdio.h>

int main(){

	float sum,sl;		//sum -> stores perimeter, sl -> temporarily stores sidelength
	int c = -1;		//counts no. of sides
	
	while (sl != 9999) {
	
		if (sl < 0) {	//for handling negative inputs
			printf( "Please enter a positive value\n");
			sl = 0;	//prevents change in total parameter
			c--;	//prevents change in no. of sides
			}
			
		sum += sl;
		c++;
		printf( "Enter value of length of side (Enter 9999 to quit): ");
		scanf("%f", &sl);	//writing this at end to ensure checking first
		}
	
	switch (c) {		//output shape as per no.of sides
		case 0:case 1:case 2: 
			printf("Not defined shape\n");
			return 0;
		case 3: 
			printf("It is a Triangle!\n");
			break;
		case 4:
			printf("It is a Quadrilateral!\n");
			break;
		case 5:
			printf("It is a Pentagon!\n");
			break;
		case 6:
			printf("It is a Hexagon!\n");
			break;
		case 7:
			printf("It is a Heptagon!\n");
			break;
		case 8:
			printf("It is a Octagon!\n");
			break;
		case 9:
			printf("It is a Nonagon!\n");
			break;
		case 10:
			printf("It is a Decagon!\n");
			break;
		default:
			printf("It is a polygon with %d sides!\n", c);
		}
		
	printf("perimeter of the polygon is %f\n",sum);
	return 0;
	
	}

		
		
