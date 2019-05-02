#include "board.h"
#include "board_print_html.h"

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
    }
}