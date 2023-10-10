//to take a user's weight and height and display BMI

#include <stdio.h>

int main(){

	float weight,height,bmi;
	
	printf("Enter weight in kgs: ");	
	scanf("%f", &weight);	//enters weight and stores it
	
	printf("\nEnter height in meters: ");
	scanf("%f", &height);	//enters height and stores it
	
	bmi=weight/(height*height);	//calculates bmi and stores it
	printf("\n\nYour BMI is: %f kg/m^2\n",bmi);	//display bmi
	
	return 0;
}
