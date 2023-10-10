//to take a user's weight and height and display BMI

//Use 2 variables, restrict to 2 decimal places

#include <stdio.h>

int main(){

	float weight,height;
	
	printf("Enter weight in kgs: ");	
	scanf("%f", &weight);	//enters weight and stores it
	
	printf("\nEnter height in meters: ");
	scanf("%f", &height);	//enters height and stores it
	
	printf("\n\nYour BMI is: %.2f kg/m^2\n",weight/(height*height));	//display bmi
	
	return 0;
}
