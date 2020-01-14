#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *current = *list;

    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }
    while (current->next) {
        current = current->next;
    }
    current->next = mx_create_node(data);
}
