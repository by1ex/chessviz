#include "check.h"
#include "board_read.h"

int Check(struct step_white* figure, char board[][8])
{
    int from_liter = (int)figure->from[0] - 97;
    int from_digit = 8 - ((int)figure->from[1] - 48) % 9;
    int to_liter = (int)figure->to[0] - 97;
    int to_digit = 8 - ((int)figure->to[1] - 48) % 9;

    if (from_liter == to_liter && from_digit == to_digit) {
        return 0;
    }
    if (figure->figure != board[from_digit][from_liter]) {
        return 3;
    }
    if ((int)board[to_digit][to_liter] == ' ' && figure->how == 'x') {
        return 4;
    }
    if ((int)board[to_digit][to_liter] != ' ' && figure->how == '-') {
        return 5;
    }
    if ((int)board[to_digit][to_liter] >= 97
        && (int)board[to_digit][to_liter] <= 122 && (int)figure->figure >= 97
        && (int)figure->figure <= 122) {
        return 6;
    }
    if ((int)board[to_digit][to_liter] >= 65
        && (int)board[to_digit][to_liter] <= 90 && (int)figure->figure >= 65
        && (int)figure->figure <= 90) {
        return 6;
    }

    if (figure->figure == 'K' || figure->figure == 'k') {
        if (abs(from_liter - to_liter) == 1
            && (abs(from_digit - to_digit) == 0
                || abs(from_digit - to_digit) == 1)) {
            return 1;
        } else if (
                abs(from_digit - to_digit) == 1
                && (abs(from_liter - to_liter) == 0
                    || abs(from_liter - to_liter) == 1)) {
            return 1;
        }
    }

    if (figure->figure == 'Q' || figure->figure == 'q') {
        if (from_digit == to_digit) {
            if (from_liter > to_liter) {
                while (1) {
                    from_liter--;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        ;
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_liter++;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_liter == to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_digit++;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_liter > to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    from_liter--;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else if (from_digit < to_digit) {
                while (1) {
                    from_digit++;
                    from_liter--;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_liter < to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    from_liter++;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else if (from_digit < to_digit) {
                while (1) {
                    from_digit++;
                    from_liter++;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        }
    }

    if (figure->figure == 'N' || figure->figure == 'n') {
        if (abs(from_digit - to_digit) == 1
            && abs(from_liter - to_liter) == 2) {
            return 1;
        }
        if (abs(from_liter - to_liter) == 1
            && abs(from_digit - to_digit) == 2) {
            return 1;
        }
    }

    if (figure->figure == 'P' || figure->figure == 'p') {
        if (figure->figure == 'P') {
            if (figure->how == '-' && from_digit == 6
                && from_liter - to_liter == 0 && from_digit - to_digit == 2
                && board[from_digit - 1][from_liter] == ' ') {
                return 1;
            } else if (
                    figure->how == 'x' && from_digit - to_digit == 1
                    && abs(from_liter - to_liter) == 1) {
                return 1;
            } else if (
                    figure->how == '-' && from_liter - to_liter == 0
                    && from_digit - to_digit == 1) {
                return 1;
            }
        } else if (figure->figure == 'p') {
            if (figure->how == '-' && from_digit == 1
                && from_liter - to_liter == 0 && to_digit - from_digit == 2
                && board[from_digit + 1][from_liter] == ' ') {
                return 1;
            } else if (
                    figure->how == 'x' && to_digit - from_digit == 1
                    && abs(from_liter - to_liter) == 1) {
                return 1;
            } else if (
                    figure->how == '-' && from_liter - to_liter == 0
                    && to_digit - from_digit == 1) {
                return 1;
            }
        } else {
        }
    }

    if (figure->figure == 'R' || figure->figure == 'r') {
        if (from_liter == to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_digit++;
                    if (from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_digit == to_digit) {
            if (from_liter > to_liter) {
                while (1) {
                    from_liter--;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else {
                while (1) {
                    from_liter++;
                    if (from_liter == to_liter)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        }
    }

    /*СЛОН*/
    if (figure->figure == 'B' || figure->figure == 'b') {
        if (from_liter > to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    from_liter--;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else if (from_digit < to_digit) {
                while (1) {
                    from_digit++;
                    from_liter--;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        } else if (from_liter < to_liter) {
            if (from_digit > to_digit) {
                while (1) {
                    from_digit--;
                    from_liter++;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            } else if (from_digit < to_digit) {
                while (1) {
                    from_digit++;
                    from_liter++;
                    if (from_liter == to_liter && from_digit == to_digit)
                        return 1;
                    if (board[from_digit][from_liter] != ' ') {
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}