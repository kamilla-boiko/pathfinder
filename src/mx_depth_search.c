#include "pathfinder.h"

static t_route *create_route(int point);
static t_stack *create_stack(int next, int next_point, int weight);
static void while_stack(t_adj **Adj, t_stack *stack_p);
static void delete_leaks(t_adj ***t, int **arr_W, int num_isl);

void mx_depth_search(t_adj **Adj, int **arr_W, char **arr, int num_isl) {
    t_stack *stack_p = NULL;

    for (int i = 0; i < num_isl; i++)
        for (int j = i + 1; j < num_isl; j++) {
            stack_p = create_stack(i, i, 0);
            while (stack_p != NULL) {
                if (stack_p->weight < arr_W[i][j]) {
                    while_stack(Adj, stack_p);
                    mx_del_first_stack(&stack_p);
                }
                else if (stack_p->next_point != j
                         || stack_p->weight > arr_W[i][j])
                    mx_del_first_stack(&stack_p);
                else {
                    mx_final_print(&stack_p->route, arr_W, arr);
                    mx_del_first_stack(&stack_p);
                }
            }
        }
    delete_leaks(&Adj, arr_W, num_isl);
}

static void delete_leaks(t_adj ***t, int **arr_W, int num_isl) {
    t_adj **Adj = *t;
    t_adj *tmp = Adj[0];

    for (int i = 0; i < num_isl; i++) {
        tmp = Adj[i];
        while (Adj[i] != NULL) {
            Adj[i] = Adj[i]->next;
            free(tmp);
            tmp = Adj[i];
        }
    }
    free(Adj);
    for (int i = 0; i < num_isl; i++)
        free(arr_W[i]);
    free(arr_W);
}

static void while_stack(t_adj **Adj, t_stack *stack_p) {
    t_adj *tmp = Adj[stack_p->next_point];

    while (Adj[stack_p->next_point] != NULL) {
        mx_stack(&stack_p, Adj[stack_p->next_point]->where,
                 Adj[stack_p->next_point]->weight);
        Adj[stack_p->next_point] = Adj[stack_p->next_point]->next; 
    }
    Adj[stack_p->next_point] = tmp;
}

static t_route *create_route(int point) {
    t_route *new_r = malloc(sizeof(t_route));

    new_r->point = point;
    new_r->next = NULL;
    return new_r;
}

static t_stack *create_stack(int next, int next_point, int weight) {
    t_stack *new_s = malloc(sizeof(t_stack));
    new_s->route = create_route(next_point);

    new_s->next_point = next;
    new_s->weight = weight;
    new_s->next = NULL;
    return new_s;
}
