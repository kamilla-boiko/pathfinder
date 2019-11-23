#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *head = list;
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
