#include "pathfinder.h"

static int hesh(char **arr, char *str);
static t_adj *new_list(char **arr, char *where, int weight);
static void push_list(char **arr, t_adj **list, char *where, int weight);

t_adj **mx_adjacency(t_road *list, char **arr, int num_isl) {
    t_adj **graph = malloc(num_isl * sizeof(t_adj *));
    int h = 0;

    for (int i = 0; i < num_isl; i++)
        graph[i] = NULL;
    while (list != NULL) {
        h = hesh(arr, list->isl1);
        if (graph[h] == NULL)
            graph[h] = new_list(arr, list->isl2, list->dist);
        else
            push_list(arr, &graph[h], list->isl2, list->dist);
        h = hesh(arr, list->isl2);
        if (graph[h] == NULL)
            graph[h] = new_list(arr, list->isl1, list->dist);
        else
            push_list(arr, &graph[h], list->isl1, list->dist);
        list = list->next;
    }
    return graph;
}

static t_adj *new_list(char **arr, char *where, int weight) {
    t_adj *list = malloc(sizeof(t_adj));

    if (list == NULL)
        return NULL;
    list->where = hesh(arr, where);
    list->weight = weight;
    list->next = NULL;
    return list;
}

static void push_list(char **arr, t_adj **list, char *where, int weight) {
    t_adj *first = *list;
    t_adj *new = new_list(arr, where, weight);

    if (*list == NULL)
        *list = new;
    new->next = first;
    *list = new;
}

static int hesh(char **arr, char *str) {
    int i = 0;

    while (mx_strcmp(arr[i], str) != 0)
        i++;
    return i;
}
