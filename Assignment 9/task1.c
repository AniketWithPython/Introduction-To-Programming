//bubble sort algorithm
// 0 <= n <= 100
// -1000 <= array[i] <= 1000

#include <stdio.h>

//functions sorted in order of invoking (i.e defining the functions in descending order in which they are invoked)

void displayArray(int arr[], int n){	//display elements of sorted array
			
	puts("Array Elements after sorting");
	
	for (size_t i = 0; i < n; ++i)
		printf("%d ",arr[i]);
	
	puts("");

}



void bubbleSort(int arr[], int n){

	int hold;	//temporary storage
	
	//bubble sort algorithm
	
	for (int i = 0; i < n; ++i){		//iterations
	
		for (size_t j = 0; j < n - 1; ++j){	//sorting passes
		
			if (arr[j] > arr[j+1]){
			
				hold = arr[j];		//store value of arr[j]
				arr[j] = arr[j+1];	//overwrite value at arr[j] 
				arr[j+1] = hold;	//overwrite value at arr[j+1]
			}
		}
	
	}
	
	displayArray(arr,n); 		//invoking next function

}

void inputArray(int arr[], int n){
	puts("Enter elements of array");
	
	for (size_t i = 0; i < n; ++i)
		scanf("%d", &arr[i]);	//store elements in array
	
	bubbleSort(arr,n);	//invoking next function

}



int main(){
	
	int n;		//size of array
	
	printf("Enter size of array: ");
	scanf("%d", &n);
	
	int arr[n];	//declaring array
	inputArray(arr,n);	//invoking first function
	
	return 0;
	
}
