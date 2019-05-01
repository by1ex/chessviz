#include "board_print_html.h"

void printHTML(char chess_board[][8], char str_info[])
{
    FILE* html_write;
    html_write = fopen("chessviz.html", "a+");
    fclose(html_write);
} 