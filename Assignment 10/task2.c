//mini sudoku game
//user enters sudoku values and positions
// matrix.dimensions = 4x4
// 1 <= matrix.values <= 4

#include <stdio.h>
#include <stdlib.h> //for rand()
#include <time.h>   //for srand(time(NULL))

void disp(int a[4][4]){     //display game board
    
    for (size_t i = 0; i < 4; ++i){
        for (size_t j = 0; j < 4; ++j){
           printf("%5d",a[i][j]);
            };
        puts(""); 
        };
        
    
    printf("\n\n");

}

void input(int a[4][4],int i, int j, int n){        //puts value 'n' at row index 'i' and column index 'j'

    a[i][j] = n;

}

int check(int a[4][4]){     //checks if sudoku condition is satisfied
   
    //i,j are row and column indices respectively

    for (size_t i = 0; i < 4; ++i){     //checking along each row

        if (a[i][0] == a[i][1] || a[i][1] == a[i][2] || a[i][2] == a[i][3] || a[i][3] == a[i][0] || a[i][0] == a[i][2] || a[i][1] == a[i][3]){

            return 0;
        }

    };

    for (size_t j = 0; j < 4; ++j){     //checking along each column

        if (a[0][j] == a[1][j] || a[1][j] == a[2][j] || a[2][j] == a[3][j] || a[3][j] == a[0][j] || a[0][j] == a[2][j] || a[1][j] == a[3][j]){

            return 0;

        }

    };

    for (size_t i = 0; i < 2; ++i){ //checking each 2x2 grid (here i and j represend a 2x2 grid position)
                                    //e.g (0,0) means grid of cells (0,0),(0,1),(1,0),(1,1)
        for (size_t j = 0; j < 2; ++j){ 

           if (a[i][j] == a[i][j + 1] || a[i][j + 1] == a[i + 1][j + 1] || a[i + 1][j + 1] == a[i + 1][j] || a[i + 1][j] == a[i][j] || a[i][j] == a[i + 1][j + 1] || a[i][j + 1] == a[i + 1][j]){
            return 0;

            } 

        }

    };

    return 1;
    
}

int win(int a[4][4]){       //to check if all cells are populated

    for (size_t i = 0; i < 3; ++i){

        for (size_t j = 0; j < 3; ++j){

           if (a[i][j] == 0){

            return 0;

            } 

        }

    };

    return 1;
}

int main(){
    int a,b,n,c;  
    int row, col, val;
    int board[4][4] = {0};  //4x4 matrix initialised to 0 in all cells
    int fixed[4][2];
    srand(time(NULL));      //randomising the rand() func
    
    for (int i = 1; i <= 4; ++i){   //populate few cells with some values
        a = rand() % 4;     //random row
        b = rand() % 4;     //random column
        board[a][b] = i;
        fixed[i-1][0] = a;
        fixed[i-1][1] = b;
    };
    while(1){

        puts("Welcome to Mini Sudoku game!");       //menu
        puts("fill the grids with digits 1,2,3,4");
        puts("Make sure that no rows, columns and 2x2 grids have the same digits");
        puts("Choose a mode");
        puts("1. Start new game");
        puts("2. Solve board");
        puts("3. Exit");
        scanf("%d", &n);

        switch(n){      

            case 1:

                disp(board);    //display initial board

                while(!(win(board))){       //game loop

                    printf("Enter value followed by row and column (e.g 4 1 2): ");
                    scanf("%d %d %d", &val, &row, &col);
                    input(board, row - 1, col - 1, val);    //indices is row - 1 and col - 1
                    disp(board);

                };

                if (check(board)){      //checking if all entries are valid or not

                    puts("Congratulations you won!");

                }
                else {

                    puts("Sorry. Try again!");

                };

                break;
            case 2:
                disp(board);
                while(!(check(board))){

                    for (size_t i = 0; i < 4; ++i){

                        for (size_t j = 0; j < 4; ++j){

                            c = 1;

                            for (size_t k = 0; k < 4; ++k){

                                if (i == fixed[k][0] && j == fixed[k][1]){
                                    c = 0;
                                }

                            };

                            if (c == 1){
                                board[i][j] = rand() % 4 + 1;
                            };
                            
                        }

                    }

                };
                disp(board);

            case 3:
                puts("Exiting");        //exit program
                return 0;

            default:
                puts("invalid input!");

        }

    }

}