#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display_board(char (*board)[10])
{
    printf(" _____________________");
    for (int i = 0; i < 10; i++) {
        printf("\n");
        printf("| ");
        for (int j = 0; j < 10; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|");
    }
    printf("\n");
    printf(" ---------------------\n");
}