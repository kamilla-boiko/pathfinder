#include "pathfinder.h"

static int hesh(char **arr, char *str);

void mx_fil_matrix(int ***arr_W, t_road *list, char **arr) {
    int **arr_w = *arr_W;

    while (list != NULL) {
        arr_w[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = list->dist;
        arr_w[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = list->dist;
        list = list->next;
    }
}

static int hesh(char **arr, char *str) {
    int i = 0;
    
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}
