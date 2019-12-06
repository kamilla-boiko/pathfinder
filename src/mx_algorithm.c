#include "pathfinder.h"

void mx_algorithm(int ***arr_W, int ***arr_H, int num_isl) {
    int **arr_w = *arr_W;
    int **arr_h = *arr_H;
    arr_h = NULL;
    for (int k = 0; k < num_isl; ++k) {
        for (int i = 0; i < num_isl; ++i) {
            for (int j = 0; j < num_isl; ++j) {
                if (arr_w[i][j] > arr_w[i][k] + arr_w[k][j])
                    arr_w[i][j] = arr_w[i][k] + arr_w[k][j];
            }
        }
    }
}
