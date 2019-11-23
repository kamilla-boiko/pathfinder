#include "libmx.h"

void swap_list(void **first, void **second) {
    void *temp = *first;
    *first = *second;
    *second = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst) { 
        return NULL;
    }
    for (t_list *i = lst; i->next; i = i->next) {
        for (t_list *j = i->next; j; j = j->next) {
            if ((*cmp)(i->data, j->data)) {
                swap_list(&i->data, &j->data);
            }
        }
    }
    return lst;
}
