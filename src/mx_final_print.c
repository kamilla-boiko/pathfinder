#include "pathfinder.h"

typedef struct s_list {
    int isl;
    struct s_list *next;
}         t_list;

void print_path(t_list *test, char **arr) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(arr[test->isl]);
    mx_printstr(" -> ");
    while (test->next->next != NULL)
        test = test->next;
    mx_printstr(arr[test->isl]);
    mx_printchar('\n');
}

void print_route(t_list *test, char **arr) {
    mx_printstr("Route: ");
    while (test->next->next != NULL) {
        mx_printstr(arr[test->isl]);
        mx_printstr(" -> ");
        test = test->next;
    }
    mx_printstr(arr[test->isl]);
    mx_printchar('\n');
}

void print_dist(t_list *test) {
    mx_printstr("Distance: ");
    while (test->next != NULL) {
        mx_printint(test->isl);
        mx_printstr(" + ");
        test = test->next;
    }
    mx_printint(test->isl);
    mx_printstr(" = ");
    mx_printint(20);
    mx_printchar('\n');
    mx_printstr("========================================\n");
}
