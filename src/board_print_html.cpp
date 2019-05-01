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
            fprintf(html_write, R"(</td>)");
        }
        fprintf(html_write, R"(</tr>)");
    }

    fclose(html_write);
}