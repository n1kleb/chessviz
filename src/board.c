#include "board.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_scan(char* ans)
{
    int i = 0;
    do {
        scanf("%c", &ans[i]);
        i++;
    } while (ans[i - 1] != '\n');
    ans[i - 1] = '\0';
}

void check_kings(char (*board)[m])
{
    int wf = 0, bf = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'k') {
                wf = 1;
            }
            if (board[i][j] == 'K') {
                bf = 1;
            }
        }
    }
    if (wf + bf == 2) {
        return;
    } else if (wf == 1 && bf == 0) {
        printf("White won.\nCongratulations!");
        _Exit(EXIT_SUCCESS);
    } else if (wf == 0 && bf == 1) {
        printf("Black won.\nCongratulations!");
        _Exit(EXIT_SUCCESS);
    } else {
        printf("Something went wrong.\n");
        _Exit(EXIT_SUCCESS);
    }
}

int check_coordinats(int* ffc, int* fsc, int* sfc, int* ssc)
{
    char str[200];
    for (int i = 0; i < 200; i++) {
        str[i] = '\0';
    }
    str_scan(str);

    if (!strcmp("exit", str)) {
        printf("Thank you for your time!\nGood luck.\n");
        _Exit(EXIT_SUCCESS);
    }

    int argn = 0;

    if (str[0] == 'a' || str[0] == 'b' || str[0] == 'c' || str[0] == 'd'
        || str[0] == 'e' || str[0] == 'f' || str[0] == 'g' || str[0] == 'h') {
        *ffc = (int)str[0] - 96;
        argn += 1;
    }
    if (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4'
        || str[1] == '5' || str[1] == '6' || str[1] == '7' || str[1] == '8') {
        *fsc = 9 - (str[1] - 48);
        argn += 1;
    }
    if (str[3] == 'a' || str[3] == 'b' || str[3] == 'c' || str[3] == 'd'
        || str[3] == 'e' || str[3] == 'f' || str[3] == 'g' || str[3] == 'h') {
        *sfc = (int)str[3] - 96;
        argn += 1;
    }
    if (str[4] == '1' || str[4] == '2' || str[4] == '3' || str[4] == '4'
        || str[4] == '5' || str[4] == '6' || str[4] == '7' || str[4] == '8') {
        *ssc = 9 - (str[4] - 48);
        argn += 1;
    }
    if (argn == 4) {
        return 1;
    } else {
        return 0;
    }
}

int step_white(char (*board)[m], int ffc, int fsc, int sfc, int ssc)
{
    if (board[fsc][ffc] == 'p') { // white pawns
        if (board[ssc][sfc] == ' ' && ffc == sfc && abs(fsc - ssc) <= 2) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 65
            && board[ssc][sfc] <= 90
            && ((fsc - 1 == ssc && ffc - 1 == sfc)
                || (fsc - 1 == ssc && ffc + 1 == sfc))) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'r') { // white rooks
        if (board[ssc][sfc] == ' ' && (ffc == sfc || fsc == ssc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 65
            && board[ssc][sfc] <= 90 && (ffc == sfc || fsc == ssc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'n') { // white knight
        if (board[ssc][sfc] == ' '
            && (pow(sfc - ffc, 2) + pow(ssc - fsc, 2)) == 5) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 65
            && board[ssc][sfc] <= 90
            && (pow(sfc - ffc, 2) + pow(ssc - fsc, 2)) == 5) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'b') { // bishop white
        if (board[ssc][sfc] == ' ' && abs(ssc - fsc) == abs(sfc - ffc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 65
            && board[ssc][sfc] <= 90 && abs(ssc - fsc) == abs(sfc - ffc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'q') { // white queen
        if (board[ssc][sfc] == ' '
            && (ffc == sfc || fsc == ssc
                || (abs(ssc - fsc) == abs(sfc - ffc)))) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' '
            && (ffc == sfc || fsc == ssc || (abs(ssc - fsc) == abs(sfc - ffc)))
            && board[ssc][sfc] >= 65 && board[ssc][sfc] <= 90) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'k') { // white king
        if (board[ssc][sfc] == ' '
            && (abs(ssc - fsc) == 1 || abs(sfc - ffc) == 1)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' '
            && (abs(ssc - fsc) == 1 || abs(sfc - ffc) == 1)
            && board[ssc][sfc] >= 65 && board[ssc][sfc] <= 90) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    return -1;
}

int step_black(char (*board)[m], int ffc, int fsc, int sfc, int ssc)
{
    if (board[fsc][ffc] == 'R') { // black rooks
        if (board[ssc][sfc] == ' ' && (ffc == sfc || fsc == ssc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 97
            && board[ssc][sfc] <= 122 && (ffc == sfc || fsc == ssc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'N') { // black knight
        if (board[ssc][sfc] == ' '
            && (pow(sfc - ffc, 2) + pow(ssc - fsc, 2)) == 5) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 97
            && board[ssc][sfc] <= 122
            && (pow(sfc - ffc, 2) + pow(ssc - fsc, 2)) == 5) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'B') { // bishop black
        if (board[ssc][sfc] == ' ' && abs(ssc - fsc) == abs(sfc - ffc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 97
            && board[ssc][sfc] <= 122 && abs(ssc - fsc) == abs(sfc - ffc)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'Q') { // black queen
        if (board[ssc][sfc] == ' '
            && (ffc == sfc || fsc == ssc
                || (abs(ssc - fsc) == abs(sfc - ffc)))) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' '
            && (ffc == sfc || fsc == ssc || (abs(ssc - fsc) == abs(sfc - ffc)))
            && board[ssc][sfc] >= 97 && board[ssc][sfc] <= 122) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'K') { // black king
        if (board[ssc][sfc] == ' '
            && (abs(ssc - fsc) == 1 || abs(sfc - ffc) == 1)) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' '
            && (abs(ssc - fsc) == 1 || abs(sfc - ffc) == 1)
            && board[ssc][sfc] >= 97 && board[ssc][sfc] <= 122) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    if (board[fsc][ffc] == 'P') { // black pawns
        if (board[ssc][sfc] == ' ' && ffc == sfc && abs(ssc - fsc) <= 2) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        if (board[ssc][sfc] != ' ' && board[ssc][sfc] >= 97
            && board[ssc][sfc] <= 122
            && ((fsc + 1 == ssc && ffc - 1 == sfc)
                || (fsc + 1 == ssc && ffc + 1 == sfc))) {
            board[ssc][sfc] = board[fsc][ffc];
            board[fsc][ffc] = ' ';
            return 1;
        }
        return 0;
    }
    return -1;
}

void init_board(char (*board)[m])
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = ' ';
        }
    }

    board[0][1] = 'a';
    board[0][2] = 'b';
    board[0][3] = 'c';
    board[0][4] = 'd';
    board[0][5] = 'e';
    board[0][6] = 'f';
    board[0][7] = 'g';
    board[0][8] = 'h';

    board[9][1] = 'a';
    board[9][2] = 'b';
    board[9][3] = 'c';
    board[9][4] = 'd';
    board[9][5] = 'e';
    board[9][6] = 'f';
    board[9][7] = 'g';
    board[9][8] = 'h';

    board[1][0] = '8';
    board[2][0] = '7';
    board[3][0] = '6';
    board[4][0] = '5';
    board[5][0] = '4';
    board[6][0] = '3';
    board[7][0] = '2';
    board[8][0] = '1';

    board[1][9] = '8';
    board[2][9] = '7';
    board[3][9] = '6';
    board[4][9] = '5';
    board[5][9] = '4';
    board[6][9] = '3';
    board[7][9] = '2';
    board[8][9] = '1';

    board[1][1] = 'R';
    board[1][2] = 'N';
    board[1][3] = 'B';
    board[1][4] = 'Q';
    board[1][5] = 'K';
    board[1][6] = 'B';
    board[1][7] = 'N';
    board[1][8] = 'R';

    board[8][1] = 'r';
    board[8][2] = 'n';
    board[8][3] = 'b';
    board[8][4] = 'q';
    board[8][5] = 'k';
    board[8][6] = 'b';
    board[8][7] = 'n';
    board[8][8] = 'r';

    board[2][1] = 'P';
    board[2][2] = 'P';
    board[2][3] = 'P';
    board[2][4] = 'P';
    board[2][5] = 'P';
    board[2][6] = 'P';
    board[2][7] = 'P';
    board[2][8] = 'P';

    board[7][1] = 'p';
    board[7][2] = 'p';
    board[7][3] = 'p';
    board[7][4] = 'p';
    board[7][5] = 'p';
    board[7][5] = 'p';
    board[7][5] = 'p';
    board[7][6] = 'p';
    board[7][7] = 'p';
    board[7][8] = 'p';
}