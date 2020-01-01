#include "pathfinder.h"

int main(int argc, char *argv[]) {
    int num_isl = 0;
    char **arr_isl = mx_printerr(argc, argv[1], &num_isl);
    char *str = mx_file_to_str(argv[1]);
    char **arr = mx_strsplit(str, '\n');
    t_road *list = mx_arr_to_list(arr, num_isl);

    mx_pathfinder(list, arr_isl, num_isl);
    // system("leaks -q pathfinder");
    return 0;
}
