#include "board.h"
#include "ctest.h"

char board[m][m];

CTEST(step_white, INCORRECT_MOVE)
{
    init_board(board);
    int result = step_white(board, 0, 0, 0, 0);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, INCORRECT_MOVE)
{
    init_board(board);
    int result = step_black(board, 0, 0, 0, 0);
    int expected = -1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_PAWN_CORRECT)
{
    init_board(board);
    int result = step_white(board, 1, 7, 1, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_PAWN_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 1, 7, 1, 2);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_PAWN_CORRECT)
{
    init_board(board);
    int result = step_black(board, 1, 2, 1, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_PAWN_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 1, 2, 1, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_ROOK_CORRECT)
{
    init_board(board);
    int result = step_white(board, 1, 8, 1, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_ROOK_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 1, 8, 2, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_ROOK_CORRECT)
{
    init_board(board);
    int result = step_black(board, 1, 1, 1, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_ROOK_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 1, 1, 2, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_KNIGHT_CORRECT)
{
    init_board(board);
    int result = step_white(board, 2, 8, 3, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_KNIGHT_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 2, 8, 2, 6);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_KNIGHT_CORRECT)
{
    init_board(board);
    int result = step_black(board, 2, 1, 3, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_KNIGHT_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 2, 1, 2, 3);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_BISHOP_CORRECT)
{
    init_board(board);
    int result = step_white(board, 3, 8, 5, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_BISHOP_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 3, 8, 5, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_BISHOP_CORRECT)
{
    init_board(board);
    int result = step_black(board, 3, 1, 5, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_BISHOP_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 3, 1, 5, 4);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_QUEEN_CORRECT)
{
    init_board(board);
    int result = step_white(board, 4, 8, 4, 6);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_QUEEN_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 4, 8, 4, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_QUEEN_CORRECT)
{
    init_board(board);
    int result = step_black(board, 4, 1, 4, 3);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_QUEEN_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 4, 1, 4, 2);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_KING_CORRECT)
{
    init_board(board);
    step_white(board, 5, 7, 5, 6);
    int result = step_white(board, 5, 8, 5, 7);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_white, WHITE_KING_INCORRECT)
{
    init_board(board);
    int result = step_white(board, 5, 8, 5, 7);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_KING_CORRECT)
{
    init_board(board);
    step_black(board, 5, 2, 5, 3);
    int result = step_black(board, 5, 1, 5, 2);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(step_black, BLACK_KING_INCORRECT)
{
    init_board(board);
    int result = step_black(board, 5, 1, 5, 2);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}