#include "pathfinder.h"

int **mx_create_matrix(int num_isl) {
    int **matrix = malloc(num_isl * sizeof(int *));
    for (int i = 0; i < num_isl; i++) {
    	matrix[i] = malloc(num_isl * sizeof(int));
        for (int k = 0; k < num_isl; k++) {
            matrix[i][k] = -1;
        }
    }
    return matrix;
}
