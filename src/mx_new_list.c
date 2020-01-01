#include "pathfinder.h"

t_road *mx_new_list(char *isl1, char *isl2, int dist) {
    t_road *list = malloc(sizeof(t_road));

    if (list == NULL)
        return NULL;
    list->isl1 = isl1;
    list->isl2 = isl2;
    list->dist = dist;
    list->next = NULL;
    return list;
}
