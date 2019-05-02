#include "board_print_html.h"

void printHTML(char chess_board[][8], char str_info[])
{
    FILE* html_write;
    html_write = fopen("chessviz.html", "a+");
    fprintf(html_write,
            "\n"
            R"(<table class="chessboard">)"
            "<caption>%s</caption>",
            str_info);
    for (int i = 0; i < 8; i++) {
        fprintf(html_write,
                "\n"
                R"(<tr>)");
        for (int j = 0; j < 8; j++) {
            fprintf(html_write,
                    "\n"
                    R"(<td>)");
            if (chess_board[i][j] != ' ') {
                if (chess_board[i][j] == 'r')
                    fprintf(html_write, R"(<span class="black rook"></span>)");
                if (chess_board[i][j] == 'n')
                    fprintf(html_write,
                            R"(<span class="black knight"></span>)");
                if (chess_board[i][j] == 'b')
                    fprintf(html_write,
                            R"(<span class="black bishop"></span>)");
                if (chess_board[i][j] == 'q')
                    fprintf(html_write, R"(<span class="black queen"></span>)");
                if (chess_board[i][j] == 'k')
                    fprintf(html_write, R"(<span class="black king"></span>)");
                if (chess_board[i][j] == 'p')
                    fprintf(html_write, R"(<span class="black pawn"></span>)");
                if (chess_board[i][j] == 'R')
                    fprintf(html_write, R"(<span class="white rook"></span>)");
                if (chess_board[i][j] == 'N')
                    fprintf(html_write,
                            R"(<span class="white knight"></span>)");
                if (chess_board[i][j] == 'B')
                    fprintf(html_write,
                            R"(<span class="white bishop"></span>)");
                if (chess_board[i][j] == 'Q')
                    fprintf(html_write, R"(<span class="white queen"></span>)");
                if (chess_board[i][j] == 'K')
                    fprintf(html_write, R"(<span class="white king"></span>)");
                if (chess_board[i][j] == 'P')
                    fprintf(html_write, R"(<span class="white pawn"></span>)");
            }
            fprintf(html_write, R"(</td>)");
        }
        fprintf(html_write, R"(</tr>)");
    }

    fclose(html_write);
}