#include "pathfinder.h"

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

static void write_to_arr(char **arr1, char **arr2) {
    int i = 0;
    int k = 0;
    while(arr1[i] != NULL) {
        arr2[k] = mx_strnew(mx_strlen(arr1[i]));
        for (int j = 0; arr1[i][j] != '\0'; j++)
            arr2[k][j] = arr1[i][j];
        while (mx_strcmp(arr2[k], arr1[i]) == 0 && arr1[i + 1] != NULL)
            i++;
    if (mx_strcmp(arr2[k], arr1[i]) == 0)
        i++;
        k++;
    }
    arr2[k] = NULL;
}

void mx_invalid_number(char **arr, int len_str) {
    int num = 0;
    for (int i = 0; arr[0][i] != '\0'; i++) 
        num = (10 * num) + arr[0][i] - 48;
    char *str = arr_to_str(arr, len_str);
    char **arr1 = mx_strsplit(str, ',');
    mx_strdel(&str);
    mx_bubble_sort(arr1, size_of_arr(arr1));
    char **arr2 = (char**)malloc((size_of_arr(arr1) + 1) * sizeof(char*));
    write_to_arr(arr1, arr2);
    mx_del_strarr(&arr1);
    int count_isl = size_of_arr(arr2);
    mx_del_strarr(&arr2);
    if (num != count_isl) {
        write(2, "error: invalid number of islands\n", 33);
        exit(0);
    }
}
