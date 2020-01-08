#include "pathfinder.h"

void mx_first_line_not_valid(char *argv) {
    char *str = mx_file_to_str(argv);

    if (str[0] == '\n') {
        write(2, "error: line 1 is not valid\n", 27);
        exit(0);
    }
    for (int i = 0; str[i] != '\n'; i++) {
        if (mx_isdigit(str[i]) == 0 || str[0] == 48) {
            write(2, "error: line 1 is not valid\n", 27);
            exit(0);
        }
    }
    mx_strdel(&str);
}
