#include "pathfinder.h"

static char *arr_to_str(char **arr, int len_str);
static int size_of_arr(char **arr);
static char **write_to_arr(char **arr1);

char **mx_invalid_number(char **arr, int len_str, int *num_isl) {
    int num = 0;
    char *str = NULL;
    char **arr1 = NULL;
    char **arr2 = NULL;

    for (int i = 0; arr[0][i] != '\0'; i++) 
        num = (10 * num) + arr[0][i] - 48;
    str = arr_to_str(arr, len_str);
    mx_del_strarr(&arr);
    arr1 = mx_strsplit(str, ',');
    mx_strdel(&str);
    arr2 = write_to_arr(arr1);
    mx_del_strarr(&arr1);
    *num_isl = size_of_arr(arr2);
    if (num != *num_isl) {
        write(2, "error: invalid number of islands\n", 33);
        exit(0);
    }
    return arr2;
}

static char *arr_to_str(char **arr, int len_str) {
    char *s = mx_strnew(len_str);
    int h = 0;

    for (int i = 1; arr[i] != NULL; i++) {
        int k = 0;
        for (; !mx_isdigit(arr[i][k]); k++) {
            if (mx_isalpha(arr[i][k]))
                s[h++] = arr[i][k];
            if (!mx_isalpha(arr[i][k]))
                s[h++] = ',';
        }
    }
    return s;
}

static int size_of_arr(char **arr) {
    int i = 0;

    while (arr[i] != NULL) {
        i++;
    }
    return i;
}

static char **write_to_arr(char **arr1) {
    char **arr2 = malloc((size_of_arr(arr1) + 1) * sizeof(char *));
    int k = 1;
    int n = 0;

    arr2[0] = mx_strnew(mx_strlen(arr1[0]));
    for (n = 0; n < mx_strlen(arr1[0]); n++)
        arr2[0][n] = arr1[0][n];
    for (int i = 1; arr1[i] != NULL; i++) {
        int j = 0;
        
        for (; mx_strcmp(arr1[i], arr2[j]) != 0 && j < k - 1; j++);
        if (j == k - 1 && mx_strcmp(arr1[i], arr2[j]) != 0) {
            arr2[k] = mx_strnew(mx_strlen(arr1[i]));
            for (n = 0; n < mx_strlen(arr1[i]); n++)
                arr2[k][n] = arr1[i][n];
            k++;
        }
    }
    arr2[k] = NULL;
    return arr2;
}

