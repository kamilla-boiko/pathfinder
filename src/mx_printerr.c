#include "pathfinder.h"

char **mx_printerr(int argc, char *argv, int *num) {
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    else {
        mx_not_exist_or_empty(argv);
        mx_first_line_not_valid(argv);
        char *str = mx_file_to_str(argv);
        int len_str = mx_strlen(str);
        char **arr = mx_strsplit(str, '\n');
        mx_strdel(&str);
        mx_line_not_valid(arr);
        arr = mx_invalid_number(arr, len_str, num);
        return arr;
    }
}
