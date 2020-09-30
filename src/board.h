#ifndef BOARD
#define BOARD
#define m 10

void str_scan(char* ans);
void init_board(char (*board)[m]);
void check_kings(char (*board)[m]);
int step_white(char (*board)[m], int ffc, int fsc, int sfc, int ssc);
int step_black(char (*board)[m], int ffc, int fsc, int sfc, int ssc);
int check_coordinats(int* ffc, int* fsc, int* sfc, int* ssc);

#endif