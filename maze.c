#include <stdio.h>
#include <conio.h>   // for getch() on Windows
#include <stdlib.h>

#define ROWS 6
#define COLS 8

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#'},
    {'#','P',' ',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#',' ',' ',' ',' ','#'},
    {'#',' ',' ','#','#','#','E','#'},
    {'#','#','#','#','#','#','#','#'}
};

int playerX = 1, playerY = 1;

void printMaze() {
    system("cls"); // clear screen (Windows)
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\nUse W/A/S/D to move. Reach 'E' to win!\n");
}

int main() {
    char move;
    printMaze();

    while(1) {
        move = getch(); // read key without Enter

        int newX = playerX, newY = playerY;

        if(move=='w') newX--;
        else if(move=='s') newX++;
        else if(move=='a') newY--;
        else if(move=='d') newY++;

        // check boundaries and walls
        if(newX>=0 && newX<ROWS && newY>=0 && newY<COLS && maze[newX][newY] != '#') {
            // move player
            maze[playerX][playerY] = ' ';
            playerX = newX; playerY = newY;

            if(maze[playerX][playerY] == 'E') {
                printMaze();
                printf("🎉 Congratulations! You reached the exit!\n");
                break;
            }

            maze[playerX][playerY] = 'P';
        }

        printMaze();
    }
    return 0;
}