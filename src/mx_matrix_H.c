#include "pathfinder.h"

// static t_turn *create(int turn);
// static void pb_turn(t_turn **list, int turn);

t_turn ***mx_matrix_H(int size) {
    t_turn ***arr_h = malloc(size * sizeof(t_turn **));

    for (int i = 0; i < size; i++) 
        arr_h[i] = malloc(size * sizeof(t_turn *));
    for (int j = 0; j < size; j++) {
        for (int h = 0; h < size; h++) {
        arr_h[j][h] = malloc(sizeof(t_turn));
        arr_h[j][h]->turn = -1;
        arr_h[j][h]->next = NULL;
        }
    }
    return arr_h;
}

// static t_turn *create(int turn) {
//     t_turn *list = malloc(sizeof(t_turn));

//     list->turn = turn;
//     list->next = NULL;
//     return list;
// }

// static void pb_turn(t_turn **list, int turn) {
//     t_turn *nlist = *list;
//     t_turn *newl = create(turn);

//     while (nlist->next != NULL)
//         nlist = nlist->next;
//     nlist->next = newl;
// }
