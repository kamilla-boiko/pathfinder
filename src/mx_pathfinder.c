#include "pathfinder.h"

void mx_pathfinder(t_road *list, char **arr, int num_isl) {
    int **arr_W = mx_create_matrix(num_isl);
    t_adj **adj = NULL;

    mx_fil_matrix(&arr_W, list, arr);
    mx_algorithm(&arr_W, num_isl);
    adj = mx_adjacency(list, arr, num_isl);
    mx_depth_search(adj, arr_W, arr, num_isl);
}
