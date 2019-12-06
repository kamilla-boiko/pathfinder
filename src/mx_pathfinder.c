#include "pathfinder.h"

static void mx_print_arr_int(int **arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            mx_printint(arr[i][k]);
            mx_printchar(' ');
        }
        mx_printchar('\n');
    }
    mx_printchar('\n');
}

t_path *mx_pathfinder(t_path *list, char **arr, int num_isl) {
    int **arr_W = mx_create_matrix(num_isl);
    int **arr_H = mx_create_matrix(num_isl);

    mx_fil_matrix(&arr_W, &arr_H, list, arr);
    mx_algorithm(&arr_W, &arr_H, num_isl);
    mx_print_arr_int(arr_W, num_isl);
    mx_printstr("-----------------------\n");
    mx_print_arr_int(arr_H, num_isl);
    t_path *a = NULL;
    return a;
}


