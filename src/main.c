#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[m][m];

    init_board(board);
    display_board(board);

    int ffc = 0, fsc = 0, sfc = 0, ssc = 0;
    char f = 0, status = 0;

    while (1) {
        if (f == 0) {
            printf("Course of white.\nStep: ");
            if (check_coordinats(&ffc, &fsc, &sfc, &ssc) == 0) {
                printf("Wrong coordinates.\n");
            } else {
                status = step_white(board, ffc, fsc, sfc, ssc);
                if (status == 0) {
                    printf("Inadmissible course.\n");
                } else if (status == -1) {
                    printf("You pick the wrong figure.\n");
                } else {
                    display_board(board);
                    f = 1;
                    check_kings(board);
                }
            }
        } else if (f == 1) {
            printf("Course of black.\nStep: ");
            if (check_coordinats(&ffc, &fsc, &sfc, &ssc) == 0) {
                printf("Wrong coordinates.\n");
            } else {
                status = step_black(board, ffc, fsc, sfc, ssc);
                if (status == 0) {
                    printf("Inadmissible course.\n");
                } else if (status == -1) {
                    printf("You pick the wrong figure.\n");
                } else {
                    display_board(board);
                    f = 0;
                    check_kings(board);
                }
            }
        }
    }
}