//Sales Analytics over a week
//user inputs data for week and then the required information needed

//variables declared to static to use memoisation i.e. remembering the outputs which eliminates the need to calculate repeteadly
//variable "check" ensures that computation is done only once throughout the duration of the code, after which static variables store the result

#include <stdio.h>
#include <float.h>	//to use FLT_MAX

char days[7][9] ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};	//declaration of a 2D array to store the days

void maximum(float data[]){
	static float max = 0;	//initialise max to 0
	static size_t index;	//declare index to remember the day
	static int check = 1;	//initialise check to 1
	if (check == 1){
		check = 0;	//check set to 0 ensuring execution of this block only once
		for (size_t i = 0; i < 7; ++i){		//find max of array
			if (data[i] > max){
				max = data[i];
				index = i;
			}
		}
	}
	printf("Max of Sales is %f on %s\n", max, days[index]);
	
};

void minimum(float data[]){
	static float min = FLT_MAX;	//initialise min to FLT_MAX
	static size_t index;		//declare index to remember the day
	static int check = 1;		//initialise check to 1
	if (check == 1){
		check = 0;		//check set to 0 ensuring execution of this block only once
		for (size_t i = 0; i < 7; ++i){		//find min of array
			if (data[i] < min){
				min = data[i];
				index = i;
			}
		}
	}
	printf("Min of Sales is %f on %s\n", min, days[index]);
	
};

void average(float data[]){
	static float avg;	//declare avg
	static int check = 1;	//initialise check to 1
	if (check == 1){
		check = 0;	//check set to 0 ensuring execution of this block only once
		for (size_t i = 0; i < 7; ++i) //find average of array
			avg += data[i];
		avg = avg/7;
	}
	printf("Avg of Sales is: %f\n", avg);
};



int main(){
	float data[7];
	puts("Enter data (from Sun to Sat):");
	for (size_t i; i < 7; ++i)
		scanf("%f", &data[i]);
	
	int c;
	
	while (1){
		
		puts("Enter your desired choice");
		puts("1. Max");
		puts("2. Min");
		puts("3. Avg");
		puts("4. Quit");
		scanf("%d", &c);
		switch (c){
			case 1:
				maximum(data);	//max sales
				break;
			case 2:
				minimum(data);	//min sales
				break;
			case 3:
				average(data);	//avg sales
				break;
			case 4:
				puts("Exiting");//exit when user wants
				return 0;
		}
	}
}




