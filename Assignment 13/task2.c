#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random obstacle positions
void generateObstacles(char** maze, int rows, int cols) {
    srand(time(NULL));
    int numObstacles = (rows * cols) / 5; // 20% of total cells as obstacles
    for (int i = 0; i < numObstacles; i++) {
        int randRow = rand() % rows;
        int randCol = rand() % cols;
        if (maze[randRow][randCol] != 'S' && maze[randRow][randCol] != 'E') {
            maze[randRow][randCol] = '#';
        }
    }
}

// Function to print the maze
void printMaze(char** maze, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to move the player
void movePlayer(char** maze, int rows, int cols, int* playerRow, int* playerCol, char direction) {
    int newRow = *playerRow;
    int newCol = *playerCol;

    switch(direction) {
        case 'W':
            newRow--;
            break;
        case 'A':
            newCol--;
            break;
        case 'S':
            newRow++;
            break;
        case 'D':
            newCol++;
            break;
        default:
            printf("Invalid input\n");
            return;
    }

    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && maze[newRow][newCol] != '#') {
        if (maze[newRow][newCol] == 'E') {
            printf("Congratulations! You reached the exit!\n");
            exit(0);
        }
        *playerRow = newRow;
        *playerCol = newCol;
    } else {
        printf("Can't go there!\n");
    }
}

int main() {
    int rows = 5;
    int cols = 5;
    
    char** maze = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        maze[i] = (char*)malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            maze[i][j] = '.';
        }
    }

    int playerRow = 1;
    int playerCol = 1;
    maze[playerRow][playerCol] = 'S';
    maze[3][3] = 'E'; // Set exit point

    generateObstacles(maze, rows, cols);
    printMaze(maze, rows, cols);

    char direction;
    while (1) {
        printf("Enter direction (WASD): ");
        scanf(" %c", &direction);
        movePlayer(maze, rows, cols, &playerRow, &playerCol, direction);
        printMaze(maze, rows, cols);
    }

    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}