#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *last = *list;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = malloc(sizeof(t_list));
    last->next->data = data;
    last->next->next = NULL;
}
