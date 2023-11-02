// Importing standard input and output functions
#include <stdio.h>
// Defining symbolic constant (number of columns in each matrix)
#define COLUMNS 3

// Function prototypes

void setZero(int mat[][COLUMNS], int m);

void input(int mat[][COLUMNS], int m);

void add(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2);

void sub(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2);

void mul(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2);

void trans(const int mat[][COLUMNS], int m);

void display(const int mat[][COLUMNS], int m);

// Main function begins here
int main() {	

	puts("INPUTTING TWO MATRICES");
	
	puts("Number of columns in both the matrices is fixed as 3\n");
	
	// Accepting number of rows for each matrix from user
	int m1, m2;
	printf("Enter number of rows in matrix 1 and matrix 2 (space-separated): ");
	scanf("%d %d", &m1, &m2);
	
	// Defining the two two-dimensional arrays (matrices)
	int mat1[m1][COLUMNS];
	int mat2[m2][COLUMNS];
	
	puts("");
	
	puts("MATRIX 1");
	input(mat1, m1);	// Populating matrix 1
	
	puts("MATRIX 2");
	input(mat2, m2);	// Populating matrix 2
	
	// Menu
	puts("This program performs operations on matrices.");
	puts("Choose one of the following tasks");
	puts("1) Addition");
	puts("2) Subtraction");
	puts("3) Multiplication");
	puts("4) Transpose");
	puts("5) Exit");
	puts("");
	
	int option = 0;		// Option from 1-5 chosen by user
	
	// Iteration begins here, continues till use chooses to exit
	while (option != 5) {
		// Accepting option from user
		printf("Enter an option from 1-5: ");
		scanf("%d", &option);
		
		switch(option) {
			case 1:
				add(mat1, mat2, m1, m2);	// Addition of two matrices
				break;
			
			case 2:
				sub(mat1, mat2, m1, m2);	// Subtraction of two matrices
				break;
			
			case 3:
				// Accepting choice from user (matrix 1 x matrix 2, or vice-versa)
				int n1, n2;
				printf("Do you want matrix1 x matrix2 (1x2) or matrix2 x matrix1 (2x1): ");
				scanf("%d x %d", &n1, &n2);
				
				// Varying order of arguments depending on user-choice
				(n1 == 1) ? mul(mat1, mat2, m1, m2) : mul(mat2, mat1, m2, m1);
				break;
			
			case 4:
				// Accepting choice from user (whether to transpose matrix 1 or 2)
				int n;
				do {
					printf("Which matrix do you want to transpose? (1/2): ");
					scanf("%d", &n);
				} while (n != 1 && n != 2);
				
				// Varying matrix to be sent for transposing depending on user-choice
				(n == 1) ? trans(mat1, m1) : trans(mat2, m2);
				break;
			
			case 5:
				break;		// User chose to exit
			
			default:
				puts("Invalid option entered!\n");	// Error message
		}
	}
	
	return 0;	// Indicates successful end of main program
}

// Function to set the elements of the matrix as 0
void set_zero(int mat[][COLUMNS], int m) {
	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < COLUMNS; j++) {
			mat[i][j] = 0;
		}
	}
}

// Function to accept the input from user and populate the matrix
void input(int mat[][COLUMNS], int m) {
	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < COLUMNS; j++) {
			printf("Enter element (%zu,%zu): ", i+1, j+1);
			scanf("%d", &mat[i][j]);
		}
		puts("");
	}
}

// Function to add two matrices
void add(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2) {
	if (m1 == m2) {
		int add_mat[m1][COLUMNS];
		for (size_t i = 0; i < m1; i++) {
			for (size_t j = 0; j < COLUMNS; j++) {
				add_mat[i][j] = mat1[i][j] + mat2[i][j];
			}
		}
		puts("RESULTANT MATRIX (Matrix 1 + Matrix 2)");
		display(add_mat, m1);
	}
	
	else {
		puts("These matrices cannot be added, as the number of rows are different.");
	}
	puts("");
}

// Function to subtract two matrices
void sub(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2) {
	if (m1 == m2) {
		int sub_mat[m1][COLUMNS];
		for (size_t i = 0; i < m1; i++) {
			for (size_t j = 0; j < COLUMNS; j++) {
				sub_mat[i][j] = mat1[i][j] - mat2[i][j];
			}
		}
		puts("RESULTANT MATRIX (Matrix 1 - Matrix 2)");
		display(sub_mat, m1);
	}
	
	else {
		puts("These matrices cannot be subtracted, as the number of rows are different.");
	}
	puts("");
}

// Function to multiply two matrices
void mul(const int mat1[][COLUMNS], const int mat2[][COLUMNS], int m1, int m2) {
	if (m2 == COLUMNS) {
		int mul_mat[m1][COLUMNS];
		set_zero(mul_mat, m1);
		for (size_t i = 0; i < m1; i++) {
			for (size_t j = 0; j < COLUMNS; j++) {
				for (size_t k = 0; k < COLUMNS; k++) {
				 	mul_mat[i][j] += mat1[i][k] * mat2[k][j];
				}
			}
		}
		puts("RESULTANT MATRIX");
		display(mul_mat, m1);
	}
	
	else {
		puts("These matrices cannot be subtracted, as the number of rows are different.");
	}
	puts("");
}

// Function to transpose a matrix
void trans(const int mat[][COLUMNS], int m) {
	puts("TRANSPOSE MATRIX");
	for (size_t i = 0; i < COLUMNS; i++) {
		for (size_t j = 0; j < m; j++) {
			printf("%d\t", mat[j][i]);
		}
		puts("");
	}
	puts("");
}

// Function to display a matrix
void display(const int mat[][COLUMNS], int m) {
	for (size_t i = 0; i < m; i++) {
		for (size_t j = 0; j < COLUMNS; j++) {
			printf("%d\t", mat[i][j]);
		}
		puts("");
	}
	puts("");
}