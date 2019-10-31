#include "libmx.h"

t_list *mx_create_node(void *data);

void mx_push_front(t_list **list, void *data) {
    t_list *front = mx_create_node(data);
    front->next = *list;
    *list = front;
}
