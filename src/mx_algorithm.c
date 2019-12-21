#include "pathfinder.h"

static t_turn *create(int turn);
static void pb_turn(t_turn **list, int turn);

// static void mx_print_arr_int(int **arr, int size) {
//     for (int i = 0; i < size; i++) {
//         for (int k = 0; k < size; k++) {
//             mx_printint(arr[i][k]);
//             mx_printchar(' ');
//         }
//         mx_printchar('\n');
//     }
//     mx_printchar('\n');
// }

void mx_algorithm(int ***arr_W, t_turn ****arr_H, int num_isl) {
    int **arr_w = *arr_W;
    t_turn ***arr_h = *arr_H;
    
    for (int k = 0; k < num_isl; k++) {
        for (int i = 0; i < num_isl; i++) {
            for (int j = 0; j < num_isl; j++) {
                if (arr_w[i][j] > arr_w[i][k] + arr_w[k][j]) {
                    arr_w[i][j] = arr_w[i][k] + arr_w[k][j];
                    arr_h[i][j]->turn = k; 
                }
                if (arr_w[i][j] == arr_w[i][k] + arr_w[k][j])
                    pb_turn(&arr_h[i][j], k);
            }
        }
    }
}

static t_turn *create(int turn) {
    t_turn *list = malloc(sizeof(t_turn));

    list->turn = turn;
    list->next = NULL;
    return list;
}

static void pb_turn(t_turn **list, int turn) {
    t_turn *nlist = *list;
    t_turn *newl = create(turn);

    while (nlist->next != NULL)
        nlist = nlist->next;
    nlist->next = newl;
}
