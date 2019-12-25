#include "pathfinder.h"

void mx_first_line_not_valid(char *argv) {
    char *str = mx_file_to_str(argv);
    
    for(int i = 0; str[i] != '\n'; i++) {
        if (mx_isdigit(str[i]) == 0) {
            write(2, "error: line 1 isn't valid\n", 26);
            exit(0);
        }
    }
    mx_strdel(&str);
}
