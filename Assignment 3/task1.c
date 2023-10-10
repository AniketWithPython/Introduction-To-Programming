//generate a temperature conversion table from fahrenheit to celsius for the provided range
//User inputs startF (starting temp) and endF (ending temp)

#include <stdio.h>

int main(){
	int startF,endF;	//delcaration of startF, endF
	
	printf("Enter starting and ending integer Fahrenheit temps seperated by space: ");	//prompt
	scanf("%d %d", &startF, &endF);		//user inputs
	
	printf("\n%-20s%-20s%s\n\n","Fahrenheit","Celsius","Kelvin");		//printing headers

	for (int i = startF; i <= endF; i++){
		printf("%-20d%-20.3f%.3f\n",i,(float)(i-32)*5/9,(float)(i-32)*5/9+273.15);	//printing values
		}
	
	return 0;
	

}
