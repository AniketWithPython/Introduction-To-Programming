//find min of array
//user inputs size and elements

#include <stdio.h>

int main(){
	int size;	//size
	int c = 0;	//counter
	
	printf("Enter array size: ");
	scanf("%d", &size);
	int arr[size];	//array declaration
	puts("Enter integers: ");
	
	for (;c < size; c++){	//collect elements
		scanf("%d", &arr[c]);
	}
	
	
	int min = arr[0];	//initialise min to first elem of array
	
	for (size_t i = 0; i < c; ++i){		//find minimum of array
		if (arr[i] < min) 
			min = arr[i];
		
	}
	
	printf("Min of array is: %d\n",min);
	
	return 0;
	
}
