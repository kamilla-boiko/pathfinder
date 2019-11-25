#include "pathfinder.h"

static void print_line_not_valid(int i) {
    write(2, "error: line ", 12);
    write(2, mx_itoa(i + 1), mx_strlen(mx_itoa(i)));
    write(2, " isn't valid\n", 13);
    exit(0);
}

void mx_line_not_valid(char **arr) {
    int i = 1;
    int k = 0;
    for(i = 1; arr[i] != NULL; i++) {
        while(arr[i][k] != '-') {
            if(mx_isalpha(arr[i][k]) == 0) {
                print_line_not_valid(i);
            }
            k++;
        }
        k++;
        while(arr[i][k] != ',') {
            if(mx_isalpha(arr[i][k]) == 0) {
                print_line_not_valid(i);
            }
            k++;
        }
        k++;
        while(arr[i][k] != '\0') {
            if(mx_isdigit(arr[i][k]) == 0) {
                print_line_not_valid(i);
            }
            k++;
        }
        k = 0;
    }
}
