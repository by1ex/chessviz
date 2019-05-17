#include "board_read.h"
#include "board_print_html.h"
#include "board_print_plain.h"

void checkSteps(char* txt, char chess_board[][8])
{
    printf("\n");
    FILE* input_file;
    input_file = fopen(txt, "a+");
    if (input_file == NULL) {
        printf("Cannot open file\n");
    }
    rewind(input_file);
    while (!feof(input_file)) {
        struct step_white sw_def = {"", 'P', "", "", ' ', ' '};
        char target = fgetc(input_file);
        struct step_white white = sw_def;
        int pars = 1;
        while (target != ' ') {
            if (!isdigit(target) && target != '.') {
                printf("Error. Was exepted digit: found - %c\n", target);
                exit(1);
            }
            if (target == '.') {
                target = fgetc(input_file);
                continue;
            }
            char bufer_temp[2] = {target, '\0'};
            strcat(white.num, bufer_temp);
            target = fgetc(input_file);
        }
        strcpy(sw_def.num, white.num);
        target = fgetc(input_file);
        int its_black = 0;
        while (1) {
            if (target == ' ' || target == '\n' || target == EOF) {
                if (target == '\n' || target == EOF) {
                    moveFigures(&white, chess_board);
                    white = sw_def;
                    its_black = 0;
                    printf("Record added!\n");
                    break;
                }
                moveFigures(&white, chess_board);
                white = sw_def;
                pars = 1;
                target = fgetc(input_file);
            }
            if (pars == 1) {
                if (target == 'K' || target == 'Q' || target == 'R'
                    || target == 'B' || target == 'N'
                    || ((int)target >= 94 && (int)target <= 122)) {
                    if ((int)target < 94 || (int)target > 122) {
                        if (its_black) {
                            white.figure = (char)(target + 32);
                            target = fgetc(input_file);
                        } else {
                            white.figure = target;
                            target = fgetc(input_file);
                        }
                    } else {
                        if (its_black) {
                            white.figure = 'p';
                        }
                    }
                    its_black = !its_black;
                    pars++;
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [K|Q|R|N|B| ]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 2) {
                if ((int)target >= 97 && (int)target <= 104) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.from, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [a-h]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 3) {
                if ((int)target >= 49 && (int)target <= 56) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.from, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [1-8]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 4) {
                if (target == '-' || target == 'x') {
                    pars++;
                    white.how = target;
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [-|x]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 5) {
                if ((int)target >= 97 && (int)target <= 104) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.to, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [a-h]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 6) {
                if ((int)target >= 49 && (int)target <= 56) {
                    pars++;
                    char bufer_temp[2] = {target, '\0'};
                    strcat(white.to, bufer_temp);
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [1-8]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
            if (pars == 7) {
                if (target == '#' || target == '+' || target == 'K'
                    || target == 'Q' || target == 'R' || target == 'B'
                    || target == 'N' || target == 'e') {
                    white.shah_mat = target;
                    target = fgetc(input_file);
                    if (target == 'e') {
                        target = fgetc(input_file);
                        target = fgetc(input_file);
                        target = fgetc(input_file);
                    }
                    target = fgetc(input_file);
                    continue;
                } else {
                    printf("Error in %s line. Was exepted [#|+|e.p|FIGURE| ]: "
                           "found - %c\n",
                           white.num,
                           target);
                    exit(1);
                }
            }
        }
    }
}

void checkRead(int Error, struct step_white* move)
{
    if (Error == 0) {
        printf("Error in %s line. Figure %c can not move from %s to %s \n",
               move->num,
               toupper(move->figure),
               move->from,
               move->to);
    }
    if (Error == 3) {
        printf("ERROR in %s line. Figure %c not found on field %s\n",
               move->num,
               toupper(move->figure),
               move->from);
    }

    if (Error == 4) {
        printf("ERROR in %s line. Type of move is 'x' but the field %s "
               "is empty.\n",
               move->num,
               move->to);
    }

    if (Error == 5) {
        printf("ERROR in %s line. Type of move is '-' but in the field %s "
               "there is a figure.\n",
               move->num,
               move->to);
    }

    if (Error == 6) {
        printf("ERROR in %s line. Type of stroke is 'x' but in the field %s "
               "there is the Union figure.\n",
               move->num,
               move->to);
    }
}