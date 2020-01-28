#include "libmx.h"

void mx_d_push_front(t_d_list **list, void *data) {
    t_d_list *new_node = mx_d_create_node(data);

    new_node->next = *list;
    if (*list)
        (*list)->prev = new_node;
    (*list) = new_node;
}
