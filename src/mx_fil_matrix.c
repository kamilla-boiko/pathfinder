#include "pathfinder.h"

static int hesh(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}

static int size_of_arr(char **arr) {
    int i = 0;
    while (arr[i] != NULL) {
    	i++;
    }
    return i;
}

static void matrix_W(int ***arr_W, char **arr) {
    int **arr_w = *arr_W;
    int inf = 999999999;
    int size = size_of_arr(arr);
    
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (i == k)
                arr_w[i][k] = 0;
            else
                arr_w[i][k] = inf;
        }
    }
}

void mx_fil_matrix(int ***arr_W, int ***arr_H, t_path *list, char **arr) {
    int **arr_w = *arr_W;
    int **arr_h = *arr_H;

    matrix_W(&arr_w, arr);
    while (list != NULL) {
        arr_w[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = list->dist;
        arr_w[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = list->dist;
        arr_h[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = hesh(arr, list->isl2);
        arr_h[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = hesh(arr, list->isl1);
        list = list->next;
    }
}
