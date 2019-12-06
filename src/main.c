#include "pathfinder.h"

int main(int argc, char *argv[]) {
	int num_isl = 0;
    char **arr_isl = mx_printerr(argc, argv[1], &num_isl);
    // arr_isl = NULL;
    char *str = mx_file_to_str(argv[1]);
    char **arr = mx_strsplit(str, '\n');
    t_path *list = mx_arr_to_list(arr);
    mx_pathfinder(list, arr_isl, num_isl);

    // while (list->next != NULL) {
    // 	printf("%s\n", list->isl1);
    // 	printf("%s\n", list->isl2);
    // 	printf("%d\n", list->dist);
    // 	list = list->next;
    // }
    // printf("%s\n", list->isl1);
    // printf("%s\n", list->isl2);
    // printf("%d\n", list->dist);
    // system("leaks -q pathfinder");
    return 0;
}
