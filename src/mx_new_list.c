#include "pathfinder.h"

t_path *mx_new_list(char *isl1, char *isl2, int dist) {
    t_path *list = malloc(sizeof(t_path));
    
    if (list == NULL)
        return NULL;
    list->isl1 = isl1;
    list->isl2 = isl2;
    list->dist = dist;
    list->next = NULL;
    return list;
}
