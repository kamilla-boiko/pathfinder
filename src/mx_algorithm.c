#include "pathfinder.h"

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

void mx_algorithm(int ***arr_W, int ***arr_H, int num_isl) {
    int **arr_w = *arr_W;
    int **arr_h = *arr_H;
    
    for (int k = 0; k < num_isl; k++) {
        for (int i = 0; i < num_isl; i++) {
            for (int j = 0; j < num_isl; j++) {
                if (arr_w[i][j] > arr_w[i][k] + arr_w[k][j]) {
                    arr_w[i][j] = arr_w[i][k] + arr_w[k][j];
                    arr_h[i][j] = k;
                    // mx_print_arr_int(arr_w, num_isl);
                    // mx_printstr("-----------------------\n");
                }
            }
        }
    }
}
