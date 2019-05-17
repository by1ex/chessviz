
#include "ctest.h"

#include "check.h"

// KING

CTEST(king, take_ally)
{
    char board[8][8] = {{'k', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', 'p', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "a8", "b7", 'x', ' '};
    ASSERT_EQUAL(6, Check(&figure, board));
}

CTEST(king, angle)
{
    char board[8][8] = {{'k', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "a8", "b7", '-', ' '};
    ASSERT_EQUAL(1, Check(&figure, board));
}

CTEST(king, edge)
{
    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {'k', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "a5", "b4", '-', ' '};
    ASSERT_EQUAL(1, Check(&figure, board));
}

CTEST(king, center)
{
    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', 'k', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "c5", "b5", '-', ' '};
    ASSERT_EQUAL(1, Check(&figure, board));
}

CTEST(king, take)
{
    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
                        {' ', ' ', ' ', 'k', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "d5", "e6", 'x', ' '};
    ASSERT_EQUAL(1, Check(&figure, board));
}

CTEST(king, let)
{
    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
                        {' ', ' ', ' ', 'k', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "d5", "e6", '-', ' '};
    ASSERT_EQUAL(5, Check(&figure, board));
}

CTEST(king, wrong_move)
{
    char board[8][8] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
                        {' ', ' ', ' ', 'k', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
    struct step_white figure = {"1", 'k', "d5", "f7", '-', ' '};
    ASSERT_EQUAL(0, Check(&figure, board));
}