#include "pathfinder.h"

void mx_printerr(int argc, char *argv) {
    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    else {
        mx_not_exist_or_empty(argv);
        mx_first_line_not_valid(argv);
        int len_str = mx_strlen(mx_file_to_str(argv));
        char **arr = mx_strsplit(mx_file_to_str(argv), '\n');
        mx_line_not_valid(arr);
        mx_invalid_number(arr, len_str);
    } 
}
