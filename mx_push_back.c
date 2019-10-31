#include "libmx.h"

t_list *mx_create_node(void *data);

void mx_push_back(t_list **list, void *data) {
    t_list *current = *list;

    if (*list == NULL) {
        return;
    }
    while (current->next) {
        current = current->next;
    }
    current->next = mx_create_node(data);
}
