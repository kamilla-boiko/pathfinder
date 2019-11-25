#include "pathfinder.h"

void mx_invalid_number(char **arr) {
    write(2, "error: invalid number of islands\n", 32);
    exit(0);
}
