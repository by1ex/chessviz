#include "board.h"
#include "board_print_html.h"
#include "stdio.h"
#include "stdlib.h"

using namespace std;

void output_board(char chess_board[8][8])
{
    int i, j;
    for (i = 7; i > -1; i--) {
        cout << i + 1 << " ";
        for (j = 0; j < 8; j++)
            cout << chess_board[i][j] << " ";
        cout << endl;
    }
    cout << "  ";
    for (i = 97; i < 105; i++)
        cout << (char)i << " ";
    cout << endl;
}

int main()
{
    char chess_board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                              {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                              {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                              {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};
    output_board(chess_board);
    return 0;
}