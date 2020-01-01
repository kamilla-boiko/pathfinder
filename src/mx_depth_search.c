#include "pathfinder.h"

static t_route *create_route(int point);
static t_stack *create_stack(int next, int next_point, int weight);
static void del_first_stack(t_stack **stack);
static void while_stack(t_adj **Adj, t_adj *tmp, t_stack *stack_p);

void mx_depth_search(t_adj **Adj, int **arr_W, char **arr, int num_isl) {
    t_stack *stack_p = NULL;
    t_adj *tmp = NULL;

    for (int i = 0; i < num_isl; i++)
        for (int j = i + 1; j < num_isl; j++) {
            stack_p = create_stack(i, i, 0);
            while (stack_p != NULL) {
                if (stack_p->weight < arr_W[i][j]) {
                    while_stack(Adj, tmp, stack_p);
                    del_first_stack(&stack_p);
                }
                else if (stack_p->next_point != j
                         || stack_p->weight > arr_W[i][j])
                    del_first_stack(&stack_p);
                else {
                    mx_final_print(&stack_p->route, arr_W, arr);
                    del_first_stack(&stack_p);
                }
            }
        }
}

static void while_stack(t_adj **Adj, t_adj *tmp, t_stack *stack_p) {
    tmp = Adj[stack_p->next_point];
    while (Adj[stack_p->next_point] != NULL) {
        mx_stack(&stack_p, Adj[stack_p->next_point]->where,
                 Adj[stack_p->next_point]->weight);
        Adj[stack_p->next_point] = Adj[stack_p->next_point]->next; 
        }
    Adj[stack_p->next_point] = tmp;
}

static void del_first_stack(t_stack **stack) {
    t_stack *Stack = *stack;

    if (Stack->next != NULL) {
        *stack = Stack->next;
        free(Stack);
    }
    else {
        free(Stack);
        *stack = NULL;
    }
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
