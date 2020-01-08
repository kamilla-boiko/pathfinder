#include "pathfinder.h"

static void print_line_not_valid(int i);

void mx_line_not_valid(char **arr) {
    for (int i = 1; arr[i] != NULL; i++) {
        int k = 0;

        for (; arr[i][k] != '-'; k++)
            if (mx_isalpha(arr[i][k]) == 0)
                print_line_not_valid(i);
        k++;
        for (; arr[i][k] != ','; k++)
            if (mx_isalpha(arr[i][k]) == 0)
                print_line_not_valid(i);
        if (arr[i][++k] == '\0')
            print_line_not_valid(i);
        if (arr[i][k] == 48) 
            print_line_not_valid(i);
        for (; arr[i][k] != '\0'; k++)
            if (mx_isdigit(arr[i][k]) == 0)
                print_line_not_valid(i);
    }
}

static void print_line_not_valid(int i) {
    write(2, "error: line ", 12);
    write(2, mx_itoa(i + 1), mx_strlen(mx_itoa(i)));
    write(2, " is not valid\n", 14);
    exit(0);
}
