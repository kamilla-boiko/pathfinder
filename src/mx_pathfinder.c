#include "pathfinder.h"

static void print_list(t_adj **adj, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", i);
        while ((*adj) != NULL) {
            printf("%d", (*adj)->where);
            printf("%c", '|');
            printf("%d", (*adj)->weight);
            printf("%s", "-->");
            (*adj) = (*adj)->next;
        }
        adj++;
        printf("\n%s\n", "=====================");

    }
}

t_road *mx_pathfinder(t_road *list, char **arr, int num_isl) {
    int **arr_W = mx_create_matrix(num_isl);
    t_adj **adj = NULL;

    mx_fil_matrix(&arr_W, list, arr);
    mx_algorithm(&arr_W, num_isl);
    adj = mx_adjacency(list, arr, num_isl);
    // mx_print_arr_int(arr_W, num_isl);
    // mx_printstr("-----------------------\n");
    // mx_print_arr_int_of_3dmx(arr_H, num_isl);
    t_road *a = NULL;
    print_list(adj, num_isl);
    return a;
}


