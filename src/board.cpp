#include "board.h"
#include "board_print_html.h"

void checkSteps(char *txt, char chess_board[][8]) {
  printf("\n");
  FILE *input_file;
  input_file = fopen(txt, "a+");
  if (input_file == NULL) {
    printf("Cannot open file\n");
  }
  rewind(input_file);
  while (!feof(input_file)) {
    char target = fgetc(input_file);
    step_white white;
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

    target = fgetc(input_file);
    bool its_black = false;
    while (1) {
    }
  }
  void moveFigures(step_white * white_step, char chess_board[][8]) {}