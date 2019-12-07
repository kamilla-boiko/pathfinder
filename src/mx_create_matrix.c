#include "pathfinder.h"

int **mx_create_matrix(int num_isl) {
    int inf = 999999999;
    int **matrix = malloc(num_isl * sizeof(int *));

    for (int i = 0; i < num_isl; i++) {
        matrix[i] = malloc(num_isl * sizeof(int));
        for (int k = 0; k < num_isl; k++) {
            if (i == k)
                matrix[i][k] = 0;
            else
                matrix[i][k] = inf;
        }
    }
    return matrix;
}
