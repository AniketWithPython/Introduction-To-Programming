//string manipulation program to perform specified tasks
//user enters strings and relevant option

// 0 <= string.length <= 100

#include <stdio.h>


void concatenateStrings(char str1[], char str2[]){	//concatenate second string to first
	
	int l1 = 0, l2 = 0;
	
	while (str1[l1] != '\0') ++l1;		//obtain lengths of the two strings
	
	while (str2[l2] != '\0') ++l2;
	
	for (size_t i = l1; i < l1 + l2 && i < 101; ++i) str1[i] = str2[i - l1];	//write the chars of second string after the first string
	
	printf("Concatenated string is: %s\n",str1);		
	
}

int findStringLength(char str[]){		//obtain length of string

	int l = 0;
	while (str[l] != '\0') ++l;
	return l;
}

int compareString(char str1[], char str2[]){	//compare strings and return outputs
	
	if (str1 == str2) return 0;
	
	if (str1 > str2) return 1;
	
	else return -1;

}

void copyString(char dest[], char src[]){	//copy src to dest
	
	dest = src;
	printf("Copied string is: %s\n", dest);

}

void reverseString(char str[]){		//reverse string 

	int l = 0;
	while (str[l] != '\0') ++l;		//obtain length
	
	char temp[l];				//temporary array to store original string
	
	for (size_t i = 0; i < l; ++i) temp[i] = str[i];	//assigning elements of str to temp
	
	for (size_t i = 0; temp[i] != '\0'; ++i) str[l-i-1] = temp[i];	//put the elements of temp in reverse order in str 
									//e.g first element goes to last, second goes to second last and so on
	printf("Reversed string: %s\n",str);

}

int main(){

	char inp1[101],inp2[101];	//declare arrays to store strings (101 to provide space for null char, though not necessary)
	puts("Enter two strings (not more than 100 characters)");
	scanf("%s %s",inp1,inp2);
	
	int c, whichone;
	
	
	while (1){	//ensure loop continues unless user exits
		
		puts("Enter your desired choice");
		puts("1. Concatenate second string to first (Will be truncated to 100 characters)");
		puts("2. Find the length of a string");
		puts("3. compare first string to second");
		puts("4. Copy first string to second");
		puts("5. Reverse a string");
		puts("6. Exit");
		scanf("%d", &c);
	
		switch (c){
		
			case 1:
				concatenateStrings(inp1,inp2);	
				break;
			case 2:
				printf("Which string to check length?(1 or 2): ");		//ask user which string to check length of
				scanf("%d", &whichone);
				
				if (whichone == 1) printf("length is: %d\n", findStringLength(inp1));	
				
				else printf("length is: %d\n", findStringLength(inp2));
				
				break;
			case 3:
				printf("Output is: %d\n",compareString(inp1,inp2));	
				break;
			case 4:
				copyString(inp2,inp1);
				break;
			case 5:
				printf("Which string to reverse?(1 or 2): ");		//ask user which string to reverse
				scanf("%d", &whichone);
				
				if (whichone == 1) reverseString(inp1);	
				
				else reverseString(inp2);
				
				break;
			case 6:
				puts("Exiting");
				return 0;
				
		}
	}
}
