#include "board_print_plain.h"
#include "board_print_html.h"
#include "board_read.h"

void moveFigures(struct step_white* white_step, char board[][8])
{
    if ((int)white_step->from[0] < 97 || (int)white_step->from[0] > 104
        || (int)white_step->from[1] < 49 || (int)white_step->from[1] > 56) {
        printf("In %s place. Field %s not found.\n",
               white_step->num,
               white_step->from);
        exit(1);
    }

    int step_liter = (int)white_step->from[0] - 97;
    int step_digit = 8 - ((int)white_step->from[1] - 48) % 9;

    if (board[step_digit][step_liter] == white_step->figure) {
        board[step_digit][step_liter] = ' ';
        if (white_step->how == 'x') {
            step_liter = (int)white_step->to[0] - 97;
            step_digit = 8 - ((int)white_step->to[1] - 48) % 9;
            if (board[step_digit][step_liter] == ' ') {
                printf("In %s place. Type of symbol %c, but in field %s dont "
                       "have figure.\n",
                       white_step->num,
                       white_step->how,
                       white_step->to);
            }
        }
        step_liter = (int)white_step->to[0] - 97;
        step_digit = 8 - ((int)white_step->to[1] - 48) % 9;
        board[step_digit][step_liter] = white_step->figure;
    } else {
        printf("In %s place. Figure %c not found on %s field.\n",
               white_step->num,
               white_step->figure,
               white_step->from);
        exit(1);
    }

    char str_info[30];
    white_step->figure = toupper(white_step->figure);
    sprintf(str_info,
            "%s. %c%s%c%s%c",
            white_step->num,
            white_step->figure,
            white_step->from,
            white_step->how,
            white_step->to,
            white_step->shah_mat);
    printHTML(board, str_info);
}