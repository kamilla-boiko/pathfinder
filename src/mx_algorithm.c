#include "pathfinder.h"

void mx_algorithm(int ***arr_W, int num_isl) {
    int **arr_w = *arr_W;
    
    for (int k = 0; k < num_isl; k++) {
        for (int i = 0; i < num_isl; i++) {
            for (int j = 0; j < num_isl; j++) {
                if (arr_w[i][j] > arr_w[i][k] + arr_w[k][j])
                    arr_w[i][j] = arr_w[i][k] + arr_w[k][j];
            }
        }
    }
}
