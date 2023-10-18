//sorting game
//user inputs indices of array elements to be swapped

// arr.length = 10
// 1 <= arr[i] <= 100

#include <stdio.h>
#include <stdlib.h>	//to include rand() function
#include <time.h>	//to include time(NULL)


int main(){
	int arr[10];	//declare int array of size 10
	int hold,c;	//hold -> temporary storage, c -> condition
	int ind1,ind2;	//indices to swap
	long long int t1,t2;	//store timestamps
	
	srand(time(NULL));	//seeding rand()
	
	for (size_t i = 0; i < 10; ++i)		//generating random array
		arr[i] = 1 + rand() % 100;
		
	
	puts("Array Elements are");	//display array
	
	for (size_t i = 0; i < 10; ++i)
		printf("%d ",arr[i]);
	
	puts("");
	
	t1 = time(NULL);		//start timer
	
	while (1) {
		
		c = 1;			//set c to 1
		
		printf("Enter indices to swap: ");
		scanf("%d %d", &ind1, &ind2);
		
		hold = arr[ind1];		//store value of arr[ind1]
		arr[ind1] = arr[ind2];		//overwrite value at arr[ind1] 
		arr[ind2] = hold;		//overwrite value at arr[ind2]
		
		
		
		puts("Array Elements after sorting");	
	
		for (size_t i = 0; i < 10; ++i)		//display array
			printf("%d ",arr[i]);
	
		puts("");
		
		for (size_t i = 0; i < 9; ++i)		//check if every element is sorted in ascending order
			if (arr[i] > arr[i+1]){
				c = 0;			//if not then set c to 0
				break;
			}
		
		if (c) break;
	
	}
	
	t2 = time(NULL);	//stop timer
	
	puts("Congratulations!!");
	printf("Time taken by you is %lld seconds\n", t2 - t1);		//display time taken
	
	return 0;
}
