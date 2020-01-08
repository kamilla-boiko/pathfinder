#include "pathfinder.h"

static void empty_line(char *str);

char **mx_printerr(int argc, char *argv, int *num) {
    char *str = NULL;
    int len_str = 0;
    char **arr = NULL;

    if (argc != 2) {
        write(2, "usage: ./pathfinder [filename]\n", 31);
        exit(0);
    }
    else {
        mx_not_exist_or_empty(argv);
        mx_first_line_not_valid(argv);
        str = mx_file_to_str(argv);
        len_str = mx_strlen(str);
        arr = mx_strsplit(str, '\n');
        mx_line_not_valid(arr);
        empty_line(str);
        mx_strdel(&str);
        arr = mx_invalid_number(arr, len_str, num);
        return arr;
    }
}

static void empty_line(char *str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] == '\n') {
            write(2, "error: line ", 12);
            write(2, mx_itoa(count + 2), mx_strlen(mx_itoa(count)));
            write(2, " is not valid\n", 14);
            exit(0);
        }
        if (str[i] == '\n')
            count++;
    }
}
