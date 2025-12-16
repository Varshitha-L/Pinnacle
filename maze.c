#include <stdio.h>
#include <conio.h>
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

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printMaze() {
    clearScreen();
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\nUse W/A/S/D to move. Reach 'E' to win!\n");
}

int main() {
    char move;
    printMaze();

    while (1) {
        move = getch();

        int newX = playerX;
        int newY = playerY;

        if (move == 'w' || move == 'W') newX--;
        else if (move == 's' || move == 'S') newX++;
        else if (move == 'a' || move == 'A') newY--;
        else if (move == 'd' || move == 'D') newY++;

        // Check boundaries and walls
        if (newX >= 0 && newX < ROWS &&
            newY >= 0 && newY < COLS &&
            maze[newX][newY] != '#') {

            // Check if exit reached BEFORE overwriting
            if (maze[newX][newY] == 'E') {
                maze[playerX][playerY] = ' ';
                playerX = newX;
                playerY = newY;
                printMaze();
                printf("🎉 Congratulations! You reached the exit!\n");
                break;
            }

            // Move player
            maze[playerX][playerY] = ' ';
            playerX = newX;
            playerY = newY;
            maze[playerX][playerY] = 'P';
        }

        printMaze();
    }

    return 0;
}
