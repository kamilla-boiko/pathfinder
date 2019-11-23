#include "pathfinder.h"

void mx_printerr(int argc, char *argv) {
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    else {
        mx_not_exist_or_empty(argv);
        mx_first_line_not_valid(argv);
        mx_line_not_valid(argv);
    }
}
