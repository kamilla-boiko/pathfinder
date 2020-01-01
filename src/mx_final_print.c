#include "pathfinder.h"

static void print_path(t_route *test, char **arr);
static void print_route(t_route *test, char **arr);
static void print_dist(t_route *test, int **arr_W);

void mx_final_print(t_route **route, int **arr_W, char **arr) {
    t_route *r = *route;

    print_path(*route, arr);
    print_route(*route, arr);
    print_dist(r, arr_W);
}

static void print_path(t_route *test, char **arr) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(arr[test->point]);
    mx_printstr(" -> ");
    while (test->next != NULL)
        test = test->next;
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}

static void print_route(t_route *test, char **arr) {
    mx_printstr("Route: ");
    while (test->next != NULL) {
        mx_printstr(arr[test->point]);
        mx_printstr(" -> ");
        test = test->next;
    }
    mx_printstr(arr[test->point]);
    mx_printchar('\n');
}

static void print_dist(t_route *test, int **arr_W) {
    t_route *t = test;

    mx_printstr("Distance: ");
    if (test->next->next != NULL) {
        while (test->next->next != NULL) {
            mx_printint(arr_W[test->point][test->next->point]);
            mx_printstr(" + ");
            test = test->next;
        }
        mx_printint(arr_W[test->point][test->next->point]);
        mx_printstr(" = ");
    }
    mx_printint(arr_W[t->point][test->next->point]);
    mx_printchar('\n');
    mx_printstr("========================================\n");
}
