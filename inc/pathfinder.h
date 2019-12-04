#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"

typedef struct s_path {
    char *isl1;
    char *isl2;
    int dist;
    struct s_path *next;
}         t_path;

char **mx_printerr(int argc, char *argv, int *num);
void mx_not_exist_or_empty(char *argv);
void mx_line_not_valid(char **arr);
void mx_first_line_not_valid(char *argv);
char **mx_invalid_number(char **arr, int len_str, int *num_isl);
t_path *mx_new_list(char *isl1, char *isl2, int dist);
void mx_push_list(t_path **list, char *isl1, char *isl2, int dist);
t_path *mx_arr_to_list(char **arr);

#endif
