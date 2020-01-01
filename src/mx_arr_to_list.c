#include "pathfinder.h"

static int atoi_mod(char *str);

t_road *mx_arr_to_list(char **arr, int i) {
    t_road *new = NULL;

    for (i = 1; arr[i] != NULL; i++) {
        int k = 0;
        int h = 0;
        char *isl1 = mx_strnew(mx_strlen_my(arr[i], '-'));
        char *isl2 = mx_strnew(mx_get_char_index(arr[i], ',') - 
                     mx_get_char_index(arr[i], '-'));

        while (arr[i][k] != '-')
            isl1[h++] = arr[i][k++];
        k++;
        h = 0;
        while (arr[i][k] != ',')
            isl2[h++] = arr[i][k++];
        k++;
        h = atoi_mod(arr[i]);
        mx_push_list(&new, isl1, isl2, h);
    }
    return new;
}

static int atoi_mod(char *str) {
    int num = 0;

    while (mx_isdigit(*str) != 1) 
        str++;
    while (mx_isdigit(*str) == 1 && *str != '\0') { 
        num = (10 * num) + *str - 48;
        str++;
    }
    return num;
}
