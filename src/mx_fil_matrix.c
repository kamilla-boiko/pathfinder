#include "pathfinder.h"

static int hesh(char **arr, char *str);

void mx_fil_matrix(int ***arr_W, t_turn ****arr_H, t_path *list, char **arr) {
    int **arr_w = *arr_W;
    t_turn ***arr_h = *arr_H;

    while (list != NULL) {
        arr_w[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = list->dist;
        arr_w[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = list->dist;

        arr_h[hesh(arr, list->isl1)][hesh(arr, list->isl2)]->turn = hesh(arr, list->isl2);
        arr_h[hesh(arr, list->isl2)][hesh(arr, list->isl1)]->turn = hesh(arr, list->isl1);
        list = list->next;
    }
}

static int hesh(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}

