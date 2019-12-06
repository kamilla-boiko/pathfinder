#include "pathfinder.h"

static int hesh(char **arr, char *str) {
    int i = 0;
    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}

static int size_of_list(t_path *list) {
    if (!list)
    	return 0;
    int count = 1;
    t_path *tmp = list;

    while (tmp->next != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

static void matrix_W(int ***arr_W, t_path *list) {
    int **arr_w = *arr_W;
    int max_int = 2147483647;
    int size = size_of_list(list);

    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            if (i == k)
                arr_w[i][k] = 0;
            else
                arr_w[i][k] = max_int;
        }
    }
}

void mx_fil_matrix(int ***arr_W, int ***arr_H, t_path *list, char **arr) {
    int **arr_w = *arr_W;
    int **arr_h = *arr_H;

    matrix_W(&arr_w, list);
    while (list != NULL) {
        arr_w[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = list->dist;
        arr_w[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = list->dist;
        arr_h[hesh(arr, list->isl1)][hesh(arr, list->isl2)] = hesh(arr, list->isl2);
        arr_h[hesh(arr, list->isl2)][hesh(arr, list->isl1)] = hesh(arr, list->isl1);
        list = list->next;
    }
}
