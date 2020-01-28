#include "libmx.h"

t_d_list *mx_d_create_node(void *data) {
    t_d_list *new_node = malloc(sizeof(t_d_list));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
