//check if array elements are mountain or not e.g 1,20,30,12,4,1
//user inputs array size and elements

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
	
	size_t index;		//initialisation of index variable to store index of max val
	int max = arr[0];	//delcaration of max to first array element
	
	for (size_t i = 0; i < c; ++i){		//find max of array and note its index
		if (arr[i] > max){
			max = arr[i];
			index = i;
		}
	}
	
	for (size_t i = 0; i <= index; ++i){	//check if elements are strictly increasing upto that index
		if (!(arr[i] < arr[i+1])) {
			puts("NO");		//if not then end program 
			return 0;
		}
	
	for (size_t i = index; i < size; ++i){	//check if elements are strictly decreasing after that index
		if (!(arr[i] > arr[i+1])) {
			puts("NO");		//if not then end program 
			return 0;
		}
	}
	
	puts("YES");				//put out yes if both condition pass
	return 0;
	
	}
}
