//check how many points lie inside a circle
//user inputs centre, radius and the points

#include <stdio.h>

int main(){
	double r,x1,y1;		//r -> radius x1,y1 -> centre coordinates
	double x,y;		//inputs for set of points
	int c = 0;		//c -> counter
	
	printf("Enter centre coordinates: ");
	scanf("%lf %lf", &x1, &y1);
	
	printf("\nEnter radius: ");
	scanf("%lf", &r);
	
	printf("Enter the points (enter 9999 in x to stop):\n");
	scanf("%lf %lf", &x, &y);
	
	while(x != 9999){
		if ((x - x1)*(x - x1) + (y - y1)*(y - y1) < r*r) c++;		//checks if inside circle and increments c by 1
		scanf("%lf %lf", &x, &y);
		}
	
	printf("No. of points inside the circle: %d\n", c);
	return 0;
} 
